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
bool thisBlockWithLeftMale(block_base * self){
    if (self->getBlockShape().connector.left == Connector::male) {
        return true;
        qDebug() << 1;
    }
    qDebug() << 0;
    return false;
}

/**
 * 查找同行的块
*/
block_base * getNearestBlockByRow(const QVector<block_base *> &blocks, const QPoint& point){
    for (auto b : blocks) {
        int diff_y = b->y() - point.y();
        if (qAbs(diff_y) < b->size().height()) {
            qDebug() << qAbs(diff_y) << b->size().height();
            return b;
        }
    }
    return nullptr;
}

/**
 * 查找同列的块
*/
block_base * getNearestBlockByColumn(const QVector<block_base *> &blocks, const QPoint& point){
    for (auto b : blocks) {
        int diff_x = b->x() - point.x();
        if (qAbs(diff_x) < b->size().width()) {
            return b;
        }
    }
    return nullptr;
}

QPoint getBlockLeftPoint(const block_base * block){
    int x = block->x() + block->block_width;
    int y = block->y();
    qDebug() << QPoint(x, y);
    return QPoint(x, y);
}

block_base* createBlock(
    const QString& block_name,
    const QPoint& point,
    const QPoint& offset,
    QWidget * target
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
    if (thisBlockWithLeftMale(new_block) ){
        block_base* left_block = getNearestBlockByRow(getAllBlock(target), point - offset);
        if (left_block) {
            new_block->move(getBlockLeftPoint(left_block));
        } else {
            new_block->move(point - offset);
        }
    } else{
        new_block->move(point - offset);
    }
    new_block->show();
    new_block->setAttribute(Qt::WA_DeleteOnClose);
    return new_block;
}