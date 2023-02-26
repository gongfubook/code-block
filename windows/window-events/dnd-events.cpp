#include "dnd-events.h"
#include "block-io.h"
#include "block-function.h"
#include "block-number.h"
#include "block-string.h"
#include "block-logic.h"
#include "block-loop.h"
#include "block-variable.h"
#include "block-list.h"
#include "block-dict.h"
#include "block-main-function.h"
#include <QVector>
#include <functional>
#include <QDebug>

QVector<block_base *> getAllBlock(QWidget * target){
    QVector<block_base *> blocks;
    for (auto child : target->children() ) {
        auto b = qobject_cast<QWidget*>(child);
        if (b) {
            auto bb = static_cast<block_base*>(b);
            if (bb) {
                qDebug() << bb->whatsThisBlockName();
                blocks.push_back(bb);
            }
        }
    }
    return blocks;
}

bool blockSortX(const block_base *a, const block_base *b) {
    if (a->x() < b->x()) {
        return true;
    }
    return false;
}

bool blockSortY(const block_base *a, const block_base *b) {
    if (a->y() < b->y()) {
        return true;
    }
    return false;
}

bool getConnectRight(block_base * self, block_base * block){
    if (self->block_shape.connector.left == Connector::male && block->block_shape.connector.right == Connector::female) {
        return true;
    }
    return false;
}

/**
 * 判断这个块是否需要一个右边的块来对接
*/
bool thisBlockLeftMale(block_base * self){
    if (self->getBlockShape().connector.left == Connector::male) {
        return true;
    }
    return false;
}

/**
 * 判断这个块是否是一个右边块
*/
bool thisBlockLeftFemale(block_base * self){
    if (self->getBlockShape().connector.left == Connector::none) {
        return true;
    }
    return false;
}

struct BlockRow{
    block_base* block;
    int diff;
};

bool blockSortRowDiff(const BlockRow a, const BlockRow b) {
    if (a.diff < b.diff) {
        return true;
    }
    return false;
}

/**
 * 查找同行的块
*/
block_base * getNearestBlockByRow(const QVector<block_base *> &blocks, const QPoint& point, const QPoint& self_pos){
    QVector<BlockRow> row_blocks;
    for (auto b : blocks) {
        if (b->pos() != self_pos) {
            int diff_y = qAbs(b->y() - point.y());
            if (diff_y < b->size().height()) {
                qDebug() << qAbs(diff_y) << b->size().height();
                row_blocks.push_back({b, diff_y});
            }
        }
    }
    if (row_blocks.empty()) {
        return nullptr;
    }
    std::sort(row_blocks.begin(), row_blocks.end(), blockSortRowDiff);
    return row_blocks[0].block;
    
}

/**
 * 查找同列的块并且确定位置
*/
QPoint getNearestBlockByColumn(const QVector<block_base *> &blocks, const QPoint& point, const QPoint& self_pos){
    QVector<block_base *> column_blocks;
    for (auto &&b : blocks) {
        if (b->pos() != self_pos) {
            int diff_x = b->x() - point.x();
            if (qAbs(diff_x) < b->size().width()) {
                qDebug() << qAbs(diff_x) << b->size().width();
                column_blocks.push_back(b);
            }
        }
    }
    if (column_blocks.empty()) {
        return point;
    }
    block_base* current_block = new block_base(nullptr);
    current_block->setWhatsThis("current_block");
    current_block->move(point);
    column_blocks.push_back(current_block);
    std::sort(column_blocks.begin(), column_blocks.end(), blockSortY);
    int index = -1;
    for (auto cb : column_blocks) {
        index += 1;
        if (cb->whatsThis() == "current_block") {
            cb->close();
            break;
        }
    }

    if (index == 0) {
        int diff_0 = column_blocks[1]->y() - point.y();
        int x = column_blocks[1]->x();
        int y = 0;
        if (diff_0 > 0) {
            y = column_blocks[1]->y() - column_blocks[1]->height() + (BLOCK_Y + 3);
        } else {
            y = column_blocks[1]->y() + column_blocks[1]->height() - (BLOCK_Y + 3);
        }
        return QPoint(x, y);
    }

    if (column_blocks.size() == index + 1) {
        int diff_0 = column_blocks[index-1]->y() - point.y();
        int x = column_blocks[index-1]->x();
        int y = 0;
        if (diff_0 > 0) {
            y = column_blocks[index-1]->y() - column_blocks[index-1]->height() + (BLOCK_Y + 3);
        } else {
            y = column_blocks[index-1]->y() + column_blocks[index-1]->height() - (BLOCK_Y + 3);
        }
        return QPoint(x, y);
    }

    int diff_0 = column_blocks[index - 1]->y() - point.y();
    int diff_1 = column_blocks[index + 1]->y() - point.y();
    if (qAbs(diff_0) < qAbs(diff_1)) {
        int x = column_blocks[index - 1]->x();
        int y = 0;
        if (diff_0 > 0) {
            y = column_blocks[index - 1]->y() - column_blocks[index - 1]->height() + (BLOCK_Y + 3);
        } else {
            y = column_blocks[index - 1]->y() + column_blocks[index - 1]->height() - (BLOCK_Y + 3);
        }
        return QPoint(x, y);
    }

    int x = column_blocks[index + 1]->x();
    int y = 0;
    if (diff_1 > 0) {
        y = column_blocks[index + 1]->y() - column_blocks[index + 1]->height() + (BLOCK_Y + 3);
    } else {
        y = column_blocks[index + 1]->y() + column_blocks[index + 1]->height() - (BLOCK_Y + 3);
    }
    return QPoint(x, y);
}

QPoint getBlockLeftPoint(const block_base * block){
    int x = block->x() + block->block_width;
    int y = block->y();
    qDebug() << QPoint(x, y);
    return QPoint(x, y);
}

/**
 * 判断当前位置是否存在代码块
*/
bool currentPointIsBlock(const QVector<block_base *> &blocks, const QPoint& self_pos){
    for (auto b : blocks) {
        auto pos = b->pos();
        auto size = b->size();
        if ((self_pos.x() >= pos.x() 
            && self_pos.x() < (pos.x() + size.width() - BLOCK_X * 2))
            && (self_pos.y() >= pos.y() 
            && self_pos.y() < (pos.y() + size.height() - BLOCK_Y * 2))
            ) {
            return true;
        }
    }
    return false;
}

block_base* createBlock(
    const QString& block_name,
    const QPoint& point,
    const QPoint& offset,
    QWidget * target,
    const QPoint& self_pos
){
    block_base* new_block = nullptr;
    if (block_name == "output") {
        new_block = new block_print(target);
    } else if (block_name == "variable") {
        new_block = new block_variable(target, false);
    } else if (block_name == "string") {
        new_block = new block_string(target, false);
    } else if (block_name == "number") {
        new_block = new block_number(target, false);
    } else if (block_name == "loop") {
        new_block = new block_loop(target);
    } else if (block_name == "list") {
        new_block = new block_list(target);
    } else if (block_name == "logic") {
        new_block = new block_logic(target);
    } else if (block_name == "dict") {
        new_block = new block_dict(target);
    } else if (block_name == "function") {
        new_block = new block_function(target, false);
    } else if (block_name == "main_function") {
        new_block = new block_main_function(target);
    }
    if (!new_block){
        return new_block;
    }

    QVector<block_base*> blocks = getAllBlock(target);
    QPoint target_pos = point - offset;

    if (thisBlockLeftFemale(new_block)) {
        target_pos = getNearestBlockByColumn(blocks, target_pos, self_pos);
    } 
    if (thisBlockLeftMale(new_block) ){
        block_base* left_block = getNearestBlockByRow(blocks, target_pos, self_pos);
        if (left_block) {
            target_pos = getBlockLeftPoint(left_block);
        } 
    } 

    if (currentPointIsBlock(blocks, target_pos)) {
        target_pos = self_pos;
    }

    new_block->move(target_pos);
    new_block->show();
    new_block->setAttribute(Qt::WA_DeleteOnClose);
    return new_block;
}