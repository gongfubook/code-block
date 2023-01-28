
#include <QtWidgets>
#include "block-list.h"

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

block_list::block_list(QWidget *parent)
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

    code_logic_list = new block_class_list(this);
    code_loop_list = new block_class_list(this);

    block_function *b_function = new block_function(this, true);
    code_function_list = new block_class_list(this);
    code_function_list->addWidget(b_function);

    code_variable_list = new block_class_list(this);
    
    block_print *b_print = new block_print(this, true);
    code_input_output_list = new block_class_list(this);
    code_input_output_list->addWidget(b_print);

    show_number();

}

void block_list::show_number(){
    code_number_list->block_class_list_show();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_string(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_show();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_logic(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_show();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_loop(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_show();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_function(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_show();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_variable(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_show();
    code_input_output_list->block_class_list_hide();
}

void block_list::show_input_output(){
    code_number_list->block_class_list_hide();
    code_string_list->block_class_list_hide();
    code_logic_list->block_class_list_hide();
    code_loop_list->block_class_list_hide();
    code_function_list->block_class_list_hide();
    code_variable_list->block_class_list_hide();
    code_input_output_list->block_class_list_show();
}

void block_list::dragEnterEvent(QDragEnterEvent *event)
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

void block_list::dragMoveEvent(QDragMoveEvent *event)
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

void block_list::dropEvent(QDropEvent *event)
{
    event->ignore();
}

void block_list::mousePressEvent(QMouseEvent *event)
{
    block_base *child = static_cast<block_base*>(childAt(event->pos()));
    if (!child){
        return;
    }
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->getPixmap() << QPoint(event->pos() - child->pos()) << child->whatsThisBlockName();

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(child->getPixmap());
    drag->setHotSpot(event->pos() - child->pos());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
    }
}