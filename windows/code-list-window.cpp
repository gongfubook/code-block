
#include <QtWidgets>
#include "code-list-window.h"
#include "block-base.h"
#include "block-io.h"
#include "block-function.h"
#include "block-size.h"
#include "block-main-function.h"
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
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        QString block_name;
        dataStream >> pixmap >> offset >> block_name;

        if (block_name == "output") {
            block_print *new_block_print = new block_print(this);
            new_block_print->setPixmap(pixmap);
            QWidget *child = childAt(event->pos());
            if (child) {
                // if (child->whatsThis() == "function" || child->whatsThis() == "main function"){
                //     qDebug() << "child->whatThis()" << child->whatsThis();
                //     qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
                //     auto cp = child->pos() + child->block_point;
                //     int x = cp.x() + BLOCK_LEFT_WIDTH - BLOCK_X;
                //     int y = cp.y() + BLOCK_HEIGHT - BLOCK_Y;
                //     Base<QWidget> *inner_child = static_cast<Base<QWidget>*>(childAt(x, y));
                //     if (inner_child && inner_child != child) {
                //         qDebug() << inner_child->whatsThis();
                //         qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
                //         qDebug() << "new_block_print->block_height" << new_block_print->block_height;
                //         child->widget_height = child->widget_height + new_block_print->block_height;
                //         child->block_height += new_block_print->block_height;

                //         qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
                //         child->createPixmap();
                //         child->update();
                //         child->show();
                //         new_block_print->move(x, y+new_block_print->block_height);
                //     } else {
                //         new_block_print->move(x, y);
                //     }
                // }
            } else {
                new_block_print->move(event->pos() - offset);
            }
            new_block_print->show();
            new_block_print->setAttribute(Qt::WA_DeleteOnClose);
        }

        if (block_name == "function") {
            block_function *new_block_function = new block_function(this, false);
            new_block_function->setPixmap(pixmap);
            new_block_function->move(event->pos() - offset);
            new_block_function->show();
            new_block_function->setAttribute(Qt::WA_DeleteOnClose);
        }

        if (block_name == "main function") {
            block_main_function *main = new block_main_function(this);
            main->move(event->pos() - offset);
            main->show();
            main->setAttribute(Qt::WA_DeleteOnClose);
        }

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

//! [1]
void code_list_window::mousePressEvent(QMouseEvent *event)
{
//     auto child = childAt(event->pos());
//     if (!child) {
//         return;
//     }
//     QByteArray itemData;
//     QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//     dataStream << child->getPixmap() << QPoint(event->pos() - child->pos()) << child->whatThis();

//     QMimeData *mimeData = new QMimeData;
//     mimeData->setData("application/x-dnditemdata", itemData);

//     QDrag *drag = new QDrag(this);
//     drag->setMimeData(mimeData);
//     drag->setPixmap(child->getPixmap());
//     drag->setHotSpot(event->pos() - child->pos());

//     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
//         child->close();
//     } else {
//         child->show();
//     }
 }
