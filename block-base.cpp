

#include "block-base.h"

#include <QPainter>
#include <QPen>


void block::paintEvent(QPaintEvent *event)
{
    //避免编译错误
    Q_UNUSED(event);
    QPainter painter(this);
    QRect rect(0,0, width, height);
    //设置当前图形视图窗口
    painter.setViewport(rect);
    painter.setWindow(0,0,120,50);
    //抗锯齿的效果
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    rect.setRect(1,1,109,48);
    painter.drawRect(rect);
    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    //电池头
    rect.setRect(110,15,10,20);
    painter.drawRect(rect);
    if(mPowerLevel>myWarnLevrl){
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }else{
        brush.setColor(mColorWarning);
        pen.setColor(mColorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if(mPowerLevel>0){
        rect.setRect(5,5,mPowerLevel,40);
        painter.drawRect(rect);
    }
    QFontMetrics textsize(this->font());
    QString powStr=QString::asprintf("%d%%",mPowerLevel);
    QRect textRect=textsize.boundingRect(powStr);
    painter.setFont(this->font());
    pen.setColor(mColorBorder);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2,23+textRect.height()/2, "基础块");
}
