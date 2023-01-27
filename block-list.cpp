
#include <QtWidgets>
#include "block-list.h"


block_list::block_list(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));

    b_str = new block_string(this, true);
    b_str->move(50, 30);
    b_str->show();

    b_print = new block_print(this, true);
    b_print->move(50, 90);
    b_print->show();

    b_function = new block_function(this, true);
    b_function->move(50, 150);
    b_function->show();

    b_number = new block_number(this, true);
    b_number->move(50, 270);
    b_number->show();
}

void block_list::show_number(){
    b_number->show();

    b_str->hide();

    b_print->hide();
    b_function->hide();
}

void block_list::show_string(){
    b_number->hide();

    b_str->show();

    b_print->hide();
    b_function->hide();
}

void block_list::show_logic(){
    b_number->hide();

    b_str->hide();

    b_print->hide();
    b_function->hide();
}

void block_list::show_loop(){
    b_number->hide();

    b_str->hide();

    b_print->hide();
    b_function->hide();
}

void block_list::show_function(){
    b_number->hide();

    b_str->hide();

    b_print->show();
    b_function->show();
}

void block_list::show_variable(){

    b_number->hide();
    b_str->hide();
    b_print->hide();
    b_function->hide();
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