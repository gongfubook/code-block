#include "block-variable.h"


#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>

block_variable::block_variable(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_variable::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    painter.setPen(Qt::white);
    painter.setBrush(color_back);
    block_path = createPath(block_point.x(), block_point.y(), block_width, block_height, block_left, block_right, block_up, block_down);
    painter.drawPath(block_path);

    painter.drawText(block_point.x() + 5, (block_height - font_size) + (block_height - font_size) / 2, block_text);
    edit = new QLineEdit(this);
    edit->setStyleSheet("QLineEdit{border-width:0;border-style:outset;background-color:white;border-radius:10px;}");
    edit->setMinimumWidth(20);
    edit->setMaximumWidth(block_width - 10);
    edit->setMinimumHeight(block_height - 10);
    edit->setMaximumHeight(block_height - 10);
    edit->move((block_width - edit->width()) / 2, block_point.y() + 6);
    edit->setText("");
    edit->setReadOnly(read_only);
    edit->show();
    painter.end();
}

void block_variable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}