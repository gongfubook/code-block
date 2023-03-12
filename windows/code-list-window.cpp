
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
    code_list_manage = new CodeListManagement(widget_height, line_height, line_start_x, this);
    // code_list_manage->addBlock()
    // block_main_function *main = new block_main_function(this);
    // main->move(this->width() / 2, this->height() / 2);
    // main->show();
}

void code_list_window::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "dragEnterEvent " << event->pos();
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
            qDebug() << event->pos();
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
        code_list_manage->dropBlock(itemData, event->pos());
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
    dataStream << child->whatsThisBlockName() << child->getPixmap() << QPoint(event->pos() - child->pos()) << child->pos();

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


void code_list_window::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(12);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 0);
    painter.setFont(font);
    painter.setPen(rgbColor(BLACK));
    painter.drawRect(QRect(0, 0, line_start_x, this->height()));
    int line_numbers = (this->height() - 10) / line_height;
    for (int i = 1; i < line_numbers; i++) {
        int y = line_height * i;
        painter.drawText(3, y, QString(std::to_string(i).c_str()));
        code_list_manage->update(i);
    }
}



