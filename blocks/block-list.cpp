#include "block-list.h"
#include "block-paint.h"

block_list::block_list(QWidget *parent=nullptr): block_base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_list::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    createText(block_pixmap, block_text, block_width);
}

QPixmap block_list::getPixmap(){
    return grab();
}

bool block_list::isParentBlock(){
    return false;
}

void block_list::insertCode(const QString &code){
    return;
}

QString block_list::toCode(){
    return code_text;
}

QString block_list::whatsThisBlockName(){
    return "list";
}

void block_list::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}