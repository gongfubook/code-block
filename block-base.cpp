

#include "block-base.h"

#include <QPainter>
#include <QPen>
#include <QDebug>


QPainterPath createPath(
    int x,
    int y,
    int width,
    int height,
    enum Connector left,
    enum Connector right,
    enum Connector up,
    enum Connector down
){
    QPainterPath path(QPointF(x, y));
    if (up == Connector::none) {
        path.lineTo(x + width, y);
    } else if (up == Connector::female) {
        path.lineTo(x + 30, y);
        path.lineTo(x + 35, y + 5);
        path.lineTo(x + 40, y);
        path.lineTo(x + width, y);
    } else {
        path.lineTo(x + 30, y);
        path.lineTo(x + 35, y - 5);
        path.lineTo(x + 40, y);
        path.lineTo(x + width, y);
    }

    if (right == Connector::none) {
        path.lineTo(x + width, y + height);
    } else if (right == Connector::female) {
        path.lineTo(x + width, y + 10);
        path.lineTo(x + width - 5, y + 5);
        path.lineTo(x + width - 5, y + 25);
        path.lineTo(x + width, y + 20);
        path.lineTo(x + width, y + height);
    } else {
        path.lineTo(x + width, y + 10);
        path.lineTo(x + width + 5, y + 5);
        path.lineTo(x + width + 5, y + 25);
        path.lineTo(x + width, y + 20);
        path.lineTo(x + width, y + height);
    }

    if (down == Connector::none) {
        path.lineTo(x, y + height);
    } else if (down == Connector::female) {
        path.lineTo(x + 40, y + height);
        path.lineTo(x + 35, y - 5 + height);
        path.lineTo(x + 30, y + height);
        path.lineTo(x, y + height);
    } else {
        path.lineTo(x + 40, y + height);
        path.lineTo(x + 35, y + 5 + height);
        path.lineTo(x + 30, y + height);
        path.lineTo(x, y + height);
    }

    if (left == Connector::none) {
        path.lineTo(x, y);
    } else if (left == Connector::female) {
        path.lineTo(x, y + 20);
        path.lineTo(x + 5, y + 25);
        path.lineTo(x + 5, y + 5);
        path.lineTo(x, y + 10);
        path.lineTo(x, y);
    } else {
        path.lineTo(x, y + 20);
        path.lineTo(x - 5, y + 25);
        path.lineTo(x - 5, y + 5);
        path.lineTo(x, y + 10);
        path.lineTo(x, y);
    }
    
    return path;

}


block_base::block_base(QWidget *parent=nullptr): QLabel(parent){
    move(widget_point);
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_TranslucentBackground);
    // setStyleSheet("background-color:red;");
}

void block_base::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    painter.setPen(Qt::white);
    painter.setBrush(color_back);
    block_text = "基础块";
    block_path = createPath(block_point.x(), block_point.y(), block_width, block_height, block_left, block_right, block_up, block_down);
    painter.drawPath(block_path);
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(font_size);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);

    painter.setFont(font);
    QFontMetrics fm = painter.fontMetrics();
    int width_text = fm.horizontalAdvance(block_text);
    painter.drawText((block_width - width_text) / 2, (block_height - font_size) + (block_height - font_size) / 2, block_text);
    painter.end();
}

void block_base::setPixmap(const QPixmap& pixmap){
    block_pixmap = pixmap;
}

QPixmap block_base::getPixmap(){
    return block_pixmap;
}

void block_base::setPoint(const QPoint& point){
    widget_point = point;
}

QPoint block_base::getPoint(){
    return widget_point;
}

QString block_base::toCode(){
    return code_text;
}

void block_base::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}

// void block::mousePressEvent(QMouseEvent *event){
//     startPos = event->pos();
//     qDebug() << "startPos: " << startPos;
// }

// void block::mouseReleaseEvent(QMouseEvent *event){
//     qDebug() << "this->pos(): "<< this->pos();
//     qDebug() << "event->pos(): "<< event->pos();
//     qDebug() << "event->pos() - startPos: "<< event->pos() - startPos;
//     // QPoint click_p = this->pos() - startPos;
//     this->move(raw_point());

// }
// void block::mouseMoveEvent(QMouseEvent *event){
//     QPoint click_p = this->pos() - startPos;
//     this->move(event->pos() + click_p);

// }
