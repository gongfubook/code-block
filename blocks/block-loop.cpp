#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>
#include "block-loop.h"

block_loop::block_loop(QWidget *parent=nullptr): block_base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background-color:white;");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_loop::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    painter.setPen(color_back);
    painter.setBrush(color_back);
    block_path = createPath(block_point.x() + BLOCK_FUNCTION_LEFT_WIDTH, block_point.y(), block_width, BLOCK_HEIGHT, block_left_up, block_right_up, block_up_up, block_down_up);
    painter.drawPath(block_path);
    block_path = createPath(block_point.x(), block_point.y(), BLOCK_FUNCTION_LEFT_WIDTH, block_height, block_left_left, block_right_left, block_up_left, block_down_left);
    painter.drawPath(block_path);
    block_path = createPath(block_point.x() + BLOCK_FUNCTION_LEFT_WIDTH, block_point.y() + BLOCK_HEIGHT * 2, block_width, BLOCK_HEIGHT, block_left_down, block_right_down, block_up_down, block_down_down);
    painter.drawPath(block_path);
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(font_size);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(block_point.x() + BLOCK_FUNCTION_LEFT_WIDTH + 5, (BLOCK_HEIGHT - font_size) + (BLOCK_HEIGHT - font_size) / 2, block_text);
    painter.end();
}

void block_loop::setPixmap(const QPixmap& pixmap){
    block_pixmap = pixmap;
}

QPixmap block_loop::getPixmap(){
    return block_pixmap;
}

void block_loop::setPoint(const QPoint& point){
    move(point);
}

QPoint block_loop::getPoint(){
    return pos();
}

QString block_loop::toCode(){
    return code_text;
}

QString block_loop::whatsThisBlockName(){
    return "logic";
}

void block_loop::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
