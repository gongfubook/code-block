
#include <QtWidgets>
#include "code-list-window.h"
#include "block-base.h"
#include "block-io.h"
#include "block-function.h"
#include "block-size.h"
#include "block-main-function.h"
#include "dnd-events.h"
#include <QDebug>


code_list_window::code_list_window(QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    block_main_function *main = new block_main_function(this);
    main->move(this->width() / 2, this->height() / 2);
    main->show();
}

void code_list_window::dragEnterEvent(QDragEnterEvent *event)
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

void code_list_window::dragMoveEvent(QDragMoveEvent *event)
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

void code_list_window::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        QString block_name;
        QPoint self_pos;
        dataStream >> pixmap >> offset >> block_name >> self_pos;

        createBlock(block_name, event->pos(), offset, this, self_pos);


    } else {
        event->ignore();
    }
}

void code_list_window::mousePressEvent(QMouseEvent *event)
{
    block_base *child = static_cast<block_base*>(childAt(event->pos()));
    if (!child) {
        return;
    }
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->getPixmap() << QPoint(event->pos() - child->pos()) << child->whatsThisBlockName() << child->pos();

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

