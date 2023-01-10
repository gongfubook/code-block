
#include <QtWidgets>
#include "block-list.h"
#include "block-base.h"
#include "block-io.h"
#include "block-function.h"

block_list::block_list(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    block_base * b = new block_base(this);
    b->move(100, 90);
    b->show();

    block_print *bp = new block_print(this, true);
    bp->move(100, 150);
    bp->show();

    block_function *bf = new block_function(this, true);
    bf->move(100, 210);
    bp->show();
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

//! [1]
void block_list::mousePressEvent(QMouseEvent *event)
{
    block_base *child = static_cast<block_base*>(childAt(event->pos()));
    if (!child){
        return;
    }

    startPos = event->pos();
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