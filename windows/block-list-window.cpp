
#include <QtWidgets>
#include "block-list-window.h"
#include "block-io.h"
#include "block-function.h"
#include "block-number.h"
#include "block-string.h"
#include "block-logic.h"
#include "block-loop.h"
#include "block-variable.h"
#include "block-list.h"
#include "block-dict.h"

block_class_list::block_class_list(QWidget *parent)
    : QWidget(parent)
{
    move(10, 10);
    setMinimumSize(200, 200);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    inner_block_list = new QVBoxLayout(this);

}
void block_class_list::addWidget(QWidget * widget){
    inner_block_list->addWidget(widget);
}

void block_class_list::block_class_list_show(){
    show();
}

void block_class_list::block_class_list_hide(){
    hide();
}

block_list_window::block_list_window(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));

    block_number *b_number = new block_number(this, true);
    code_number_list = new block_class_list(this);
    code_number_list->addWidget(b_number);

    block_string *b_str = new block_string(this, true);
    code_string_list = new block_class_list(this);
    code_string_list->addWidget(b_str);

    block_logic *b_logic = new block_logic(this);
    code_logic_list = new block_class_list(this);
    code_logic_list->addWidget(b_logic);

    block_loop *b_loop = new block_loop(this);
    code_loop_list = new block_class_list(this);
    code_loop_list->addWidget(b_loop);

    block_function *b_function = new block_function(this, true);
    code_function_list = new block_class_list(this);
    code_function_list->addWidget(b_function);

    block_variable *b_variable = new block_variable(this, true);
    code_variable_list = new block_class_list(this);
    code_variable_list->addWidget(b_variable);
    
    block_print *b_print = new block_print(this);
    code_input_output_list = new block_class_list(this);
    code_input_output_list->addWidget(b_print);

    block_list *b_list = new block_list(this);
    code_list_list = new block_class_list(this);
    code_list_list->addWidget(b_list);

    block_dict *b_dict = new block_dict(this);
    code_dict_list = new block_class_list(this);
    code_dict_list->addWidget(b_dict);

    show_number();

}

void block_list_window::show_number(){
    code_number_list->block_class_list_show();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_string(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_show();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_logic(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_show();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_loop(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_show();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_function(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_show();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_variable(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_show();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_input_output(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_show();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_list() {
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_show();
    code_dict_list->block_class_list_hide();
}

void block_list_window::show_dict() {
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
    code_list_list->block_class_list_hide();
    code_dict_list->block_class_list_show();
}

void block_list_window::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void block_list_window::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void block_list_window::dropEvent(QDropEvent *event)
{
    event->ignore();
}

void block_list_window::mousePressEvent(QMouseEvent *event)
{
    auto  x  = (block_base*)(childAt(event->pos()));
    if (!x){
        return;
    }
    qDebug() << "mousePressEvent whatsThis -> " << x->whatsThisBlockName();
    // QByteArray itemData;
    // QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    // dataStream << child->getPixmap() << QPoint(event->pos() - child->pos()) << child->whatsThisBlockName();

    // QMimeData *mimeData = new QMimeData;
    // mimeData->setData("application/x-dnditemdata", itemData);

    // QDrag *drag = new QDrag(this);
    // drag->setMimeData(mimeData);
    // drag->setPixmap(child->getPixmap());
    // drag->setHotSpot(event->pos() - child->pos());

    // if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
    //     child->close();
    // } else {
    //     child->show();
    // }
}