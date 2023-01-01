

#include "block-base.h"

#include <QPainter>
#include <QPen>



block::block(QWidget *parent=nullptr): QWidget(parent){
    resize(width + 2, height + 2);
    move(x, y); 
    setAcceptDrops(true);  
}


QPainterPath block::generate_path(){

    QPainterPath path(QPointF(x, y));

    path.lineTo(x, y + width);
    path.lineTo(x + height, y + width);
    path.lineTo(x + height, y);
    path.lineTo(x, y);
    return path;
    
}


void block::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
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
    pen.setWidth(2);
    painter.setPen(pen);

    QString text = "基础块";
    QPainterPath path = generate_path();
    path.setFillRule(Qt::WindingFill);
    painter.drawPath(path);
    painter.fillPath(path, QBrush(mColorBack));
    QTextOption option;
    option.setAlignment(Qt::AlignCenter);
    painter.drawText(x + width / 2, y + height / 2, text);
    //painter.drawText(info_rect, text, option);
    painter.end();
    QWidget::paintEvent(event);
}
