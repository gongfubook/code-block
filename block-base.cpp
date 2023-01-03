

#include "block-base.h"

#include <QPainter>
#include <QPen>
#include <QDebug>


block::block(QWidget *parent=nullptr): QWidget(parent){
    resize(block_width + 2, block_height + 2);
    move(block_x, block_y); 
    setAcceptDrops(true);  
    setStyleSheet("background-color:red;");
}


QPainterPath block::generate_path(){
    int start_x = 0;
    int start_y = 0;
    QPainterPath path(QPointF(start_x, start_y));
    path.lineTo(start_x + block_width, start_y);
    path.lineTo(start_x + block_width, start_y + block_height);
    path.lineTo(start_x, start_y + block_height);
    path.lineTo(start_x, start_y);
    return path;
    
}


void block::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // if (!isHovered)
    // {
    //     const QColor color(50, 50, 63);
    //     painter.setPen(color);
    // }
    // else
    // {
    //     const QColor color(86, 85, 96);
    //     painter.setPen(color);
    // }

    const QColor color(86, 85, 96);
    QPen pen;
    pen.setColor(mColorBorder);
    pen.setWidth(1);
    painter.setPen(pen);
    QString text = "基础块";
    QPainterPath path = generate_path();
    painter.drawPath(path);


    QFont font;
    font.setFamily("Microsoft YaHei");
    // 大小
    font.setPointSize(font_size);

    // 设置字符间距
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    // 使用字体
    painter.setFont(font);

    QFontMetrics fm = painter.fontMetrics();
    int width_text = fm.horizontalAdvance(text);
    
    painter.drawText((this->width() - width_text) / 2, (this->height() - font_size) + (this->height() - font_size) / 3, text);

    // painter.end();
    // QWidget::paintEvent(event);
}

void block::mousePressEvent(QMouseEvent *event){
    startPos = event->pos();
    qDebug() << "startPos: " << startPos;
}

void block::mouseReleaseEvent(QMouseEvent *event){
    qDebug() << "this->pos(): "<< this->pos();
    qDebug() << "event->pos(): "<< event->pos();
    qDebug() << "event->pos() - startPos: "<< event->pos() - startPos;
    QPoint click_p = this->pos() - startPos;
    this->move(event->pos() + click_p);

}
void block::mouseMoveEvent(QMouseEvent *event){
    QPoint click_p = this->pos() - startPos;
    this->move(event->pos() + click_p);

}
