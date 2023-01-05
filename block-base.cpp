

#include "block-base.h"

#include <QPainter>
#include <QPen>
#include <QDebug>


block::block(QWidget *parent=nullptr): QLabel(parent){
    resize(block_width+2, block_height+2);
    block_pixmap = QPixmap(block_width, block_height);
    block_pixmap.fill(Qt::white);
    QPainter painter(&block_pixmap);
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
    block_text = "基础块";
    block_path = generate_path();
    painter.drawPath(block_path);


    QFont font;
    font.setFamily("Microsoft YaHei");
    // 大小
    font.setPointSize(font_size);

    // 设置字符间距
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    // 使用字体
    painter.setFont(font);

    QFontMetrics fm = painter.fontMetrics();
    int width_text = fm.horizontalAdvance(block_text);
    
    painter.drawText((this->width() - width_text) / 2, (this->height() - font_size) + (this->height() - font_size) / 3, block_text);

    painter.end();
    // this->setPixmap(block_pixmap);
    move(block_x, block_y); 
    setAcceptDrops(true);  
    //setStyleSheet("background-color:red;");
}

QPoint block::raw_point(){
    return QPoint(block_x, block_y);
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
    painter.drawPixmap(QPoint(0,0), block_pixmap);
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
