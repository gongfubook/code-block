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