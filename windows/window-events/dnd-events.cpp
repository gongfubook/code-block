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


/**
 * 判断这个块是否需要一个左边的块来对接
*/
bool thisBlockLeftMale(block_base * self){
    if (self->getBlockShape().connector.left == Connector::male) {
        return true;
    }
    return false;
}

/**
 * 判断这个块是否是一个左边块
*/
bool thisIsLeftBlock(block_base * self){
    if (self->getBlockShape().connector.left == Connector::none) {
        return true;
    }
    return false;
}


CodeListManagement::CodeListManagement(const int widget_height, const int line_height, const int start_x, QWidget * parent): 
    widget_height(widget_height), line_height(line_height), start_x(start_x), parent(parent)
{
    int line_numbers = widget_height / line_height;
    for (int i = 1; i < line_numbers + 1; i++) {
        if (lines.find(i) == lines.end()){
            lines.insert(i, {line_height * i - 25, start_x, {}});
        }
    }
}

block_base* CodeListManagement::createBlock(const QString &block_name){
    block_base* new_block = nullptr;
    if (block_name == "output") {
        new_block = new block_print(parent);
    } else if (block_name == "variable") {
        new_block = new block_variable(parent, false);
    } else if (block_name == "string") {
        new_block = new block_string(parent, false);
    } else if (block_name == "number") {
        new_block = new block_number(parent, false);
    } else if (block_name == "loop") {
        new_block = new block_loop(parent);
    } else if (block_name == "list") {
        new_block = new block_list(parent);
    } else if (block_name == "logic") {
        new_block = new block_logic(parent);
    } else if (block_name == "dict") {
        new_block = new block_dict(parent);
    } else if (block_name == "function") {
        new_block = new block_function(parent, false);
    } else if (block_name == "main_function") {
        new_block = new block_main_function(parent);
    }
    return new_block;
}

int CodeListManagement::getCurrentLine(const QPoint& point){
    struct row_diff{
        int line_number;
        int diff;
    };
    QVector<row_diff> row_diffs;
    for (auto line_number : lines.keys()){
        auto line = lines[line_number];
        int diff_y = qAbs(line.start_y - point.y());
        row_diffs.push_back({line_number, diff_y});
        qDebug() << line_number << " : " << line.start_y << " : " << qAbs(line.start_y - point.y());

    }
    std::sort(row_diffs.begin(), row_diffs.end(), [](const row_diff& a, const row_diff& b){ return a.diff < b.diff;});
    for (auto row : row_diffs){
        qDebug() << row.line_number << " : " << row.diff;
    }
    return row_diffs[0].line_number;
}

void CodeListManagement::dropBlock(QByteArray &itemData, const QPoint &offset){
    QDataStream dataStream(&itemData, QIODevice::ReadOnly);
    QPixmap pixmap;
    QPoint point;
    QString block_name;
    QPoint self_pos;
    dataStream >> block_name >> pixmap >> point >> self_pos;
    block_base* block = createBlock(block_name);
    QPoint target = offset - point;
    qDebug() <<  target << "target";
    if (self_pos == QPoint(0, 0)) {
        addBlock(block, target);
        return;
    }
    moveBlock(block, target, self_pos);
}


void CodeListManagement::addBlock(block_base *block, const QPoint& point){
    auto line_number = getCurrentLine(point);
    qDebug() << "addBlock" << line_number;
    qDebug() << lines[line_number].blocks.size();
    if (lines[line_number].blocks.empty()) {
        qDebug() << "empty";
        if (thisIsLeftBlock(block)) {
            appendBlockofLine(line_number, block);
        } else {
            block->close();
        } 
    } else {
        qDebug() << "no empty";
        if (thisBlockLeftMale(block)) {
            qDebug() << "right block";
            appendBlockofLine(line_number, block);
        } else {
            block->close();
        } 
    }
}

void CodeListManagement::moveBlock(block_base *block, const QPoint& point, const QPoint& self_pos){
    auto line_number = getCurrentLine(point);
    if (thisIsLeftBlock(block)) {
        appendBlockofLine(line_number, block);
    } else {
        block->move(self_pos);
        block->show();
    } 
}

void CodeListManagement::appendBlockofLine(const int line_number, block_base* block){
    qDebug() << "lines[line_number].start_x" << lines[line_number].start_x;
    block->move(lines[line_number].start_x, lines[line_number].start_y);
    block->show();
    qDebug() << "current_line size" << lines[line_number].blocks.size();
    lines[line_number].blocks.push_back(block);
    qDebug() << "current_line size" << lines[line_number].blocks.size();
    int row = block->getBlockRow();
    if (row == 1) {
        auto shape = block->getBlockShape();
        lines[line_number].start_x = lines[line_number].start_x + shape.block_width;
    } else if (row > 1 && block->getBlockType() == BlockType::with_inside) {
        qDebug() << "BlockType::with_inside";
        auto shapes = block->getBlockShapes();
        lines[line_number].start_x = lines[line_number].start_x + shapes[0].block_width + BLOCK_LEFT_WIDTH;
        for (int i = line_number + 1; i < line_number + row - 1; i++) {
            qDebug() << i;
            qDebug() <<  lines[i].start_x;
            lines[i].start_x = lines[i].start_x + BLOCK_LEFT_WIDTH;
            qDebug() << lines[i].start_x;
        }
        lines[line_number+row-1].start_x = lines[line_number+row-1].start_x + shapes[1].block_width + BLOCK_LEFT_WIDTH;
    }

}

void CodeListManagement::update(const int line_number){
    if (lines.find(line_number) == lines.end()){
        lines.insert(line_number, {line_height * line_number - 25 , start_x, {}});
    }
}


void CodeListManagement::inseatUpdateBlock(QByteArray &itemData, const QPoint& point){
    auto line_number = getCurrentLine(point);
    if (lines[line_number].blocks.isEmpty()) {
        return;
    }
    if (lines[line_number].start_x > (start_x + BLOCK_LEFT_WIDTH)){
        if (point.x() >= lines[line_number].start_x) {
            return;
        } else {
            for (int i = line_number - 2; i > 0; i--){
                if (!lines[i].blocks.empty()) {
                    for (auto && b : lines[i].blocks) {

                    }
                }
            }
            
        }
    }

}

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