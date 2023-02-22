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

QVector<block_base *> getNearestBlock(const QVector<block_base *> &blocks, const QPoint &point){
    auto blocks_x = blocks;
    auto blocks_y = blocks;
    std::sort(blocks_x.begin(), blocks_x.end(), blockSortX);
    std::sort(blocks_y.begin(), blocks_y.end(), blockSortY);
    QVector<block_base *> nearest_blocks;
    for (auto b : blocks) {

    }
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
    new_block->move(point - offset);
    new_block->show();
    new_block->setAttribute(Qt::WA_DeleteOnClose);
    return new_block;
}