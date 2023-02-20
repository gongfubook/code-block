#include "block-base.h"
#include <QPainter> 

block_base::block_base(QWidget *parent=nullptr): QLabel(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_TranslucentBackground);
}

void block_base::createPixmap(){}

QPixmap block_base::getPixmap(){
    return grab();
}

bool block_base::isParentBlock(){
    return false;
}

void block_base::insertCode(const QString &code){
    return;
}

QString block_base::toCode(){
    return code_text;
}

QString block_base::whatsThisBlockName(){
    return "base";
}

void block_base::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}

