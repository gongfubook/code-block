
#include <QtWidgets>
#include "block-list.h"
#include "block-base.h"


block_list::block_list(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    block * b = new block(this);
    b->move(100, 90);
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
        // block *child = static_cast<block*>(childAt(event->pos()));
        // if (!child){
        //     return;
        // }
        // childPos = child->pos();
        // QPoint click_p = childPos - startPos;
        // child->move(event->pos() + click_p);
        // child->update();
    } else {
        event->ignore();
    }
}

void block_list::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPainterPath path;
        QPoint offset;
        dataStream >> path >> offset;

        block *new_block = new block(this);
        new_block->move(event->pos() - offset);
        new_block->show();
        new_block->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        // block *child = static_cast<block*>(childAt(event->pos()));
        // if (!child){
        //     return;
        // }
        // child->move(child->raw_point());
        // child->update();
    } else {
        event->ignore();
    }
}

//! [1]
void block_list::mousePressEvent(QMouseEvent *event)
{
    block *child = static_cast<block*>(childAt(event->pos()));
    if (!child){
        return;
    }
        

    // QPixmap pixmap = child->pixmap(Qt::ReturnByValue);
    startPos = event->pos();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->generate_path() << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos() - child->pos());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
    }
}