
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
    // if (event->mouseButtons() == Qt::LeftButton)
	// {
	// 	startPos = event->pos();
	// }
}

void block_list::dragMoveEvent(QDragMoveEvent *event)
{
    // if (event->mouseButtons() == Qt::LeftButton)
	// {
	// 	if ((event->pos() - startPos).manhattanLength() >= QApplication::startDragDistance())
	// 	{
	// 		QDrag *drag = new QDrag(this);
	// 		QMimeData *data = new QMimeData();
	// 		drag->setMimeData(data);
	// 		drag->exec(Qt::LinkAction);
	// 	}
	// }

}

void block_list::dropEvent(QDropEvent *event)
{
    // if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    //     QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
    //     QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    //     QWidget pixmap;
    //     QPoint offset;
    //     dataStream >> pixmap >> offset;

    //     QLabel *newIcon = new QLabel(this);
    //     newIcon->setPixmap(pixmap);
    //     newIcon->move(event->pos() - offset);
    //     newIcon->show();
    //     newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //     if (event->source() == this) {
    //         event->setDropAction(Qt::MoveAction);
    //         event->accept();
    //     } else {
    //         event->acceptProposedAction();
    //     }
    // } else {
    //     event->ignore();
    // }
}

//! [1]
void block_list::mousePressEvent(QMouseEvent *event)
{
//     QWidget *child = static_cast<QWidget*>(childAt(event->pos()));
//     if (!child)
//         return;

//     QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

//     QByteArray itemData;
//     QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//     dataStream << pixmap << QPoint(event->pos() - child->pos());
// //! [1]

// //! [2]
//     QMimeData *mimeData = new QMimeData;
//     mimeData->setData("application/x-dnditemdata", itemData);
// //! [2]

// //! [3]
//     QDrag *drag = new QDrag(this);
//     drag->setMimeData(mimeData);
//     drag->setPixmap(pixmap);
//     drag->setHotSpot(event->pos() - child->pos());
// //! [3]

//     QPixmap tempPixmap = pixmap;
//     QPainter painter;
//     painter.begin(&tempPixmap);
//     painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
//     painter.end();

//     child->setPixmap(tempPixmap);

//     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
//         child->close();
//     } else {
//         child->show();
//         child->setPixmap(pixmap);
//     }
}
