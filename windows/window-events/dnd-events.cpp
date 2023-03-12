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
 * 判断这个块是否需要一个右边的块来对接
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

Line CodeListManagement::getCurrentLine(const QPoint& point){
    struct row_diff{
        int line_number;
        int diff;
    };
    QVector<row_diff> row_diffs;
    for (auto line_number : lines.keys()){
        auto line = lines[line_number];
        if (line.blocks.empty()) {
            int diff_y = qAbs(line.start_y - point.y());
            row_diffs.push_back({line_number, diff_y});
        }

        qDebug() << line_number << " : " << line.start_y << " : " << qAbs(line.start_y - point.y());

    }
    std::sort(row_diffs.begin(), row_diffs.end(), [](const row_diff& a, const row_diff& b){ return a.diff < b.diff;});
    for (auto row : row_diffs){
        qDebug() << row.line_number << " : " << row.diff;
    }
    auto current_line = lines[row_diffs[0].line_number];
    return current_line;
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
    Line current_line = getCurrentLine(point);
    if (current_line.blocks.empty()) {
        if (thisIsLeftBlock(block)) {
            block->move(start_x, current_line.start_y);
            block->show();
            current_line.blocks.push_back(block);
        } else {
            block->close();
        } 
    } else {
        if (thisIsLeftBlock(block)) {
            block->move(30, current_line.start_y);
            block->show();
            current_line.blocks.push_back(block);
        } else {
            block->close();
        } 
    }
}

void CodeListManagement::moveBlock(block_base *block, const QPoint& point, const QPoint& self_pos){
    Line current_line = getCurrentLine(point);
    if (current_line.blocks.empty()) {
        if (thisIsLeftBlock(block)) {
            block->move(start_x, current_line.start_y);
            current_line.blocks.push_back(block);
        } else {
            block->move(self_pos);
        } 
    } else {
        ;
    }
}

void CodeListManagement::appendBlockofLine(const int line_number, Line &current_line, block_base* block){
    block->move(current_line.start_x, current_line.start_y);
    block->show();
    current_line.blocks.push_back(block);

}

void CodeListManagement::update(const int line_number){
    if (lines.find(line_number) == lines.end()){
        lines.insert(line_number, {line_height * line_number - 25 , start_x, {}});
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