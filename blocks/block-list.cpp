#include "block-list.h"
#include "block-paint.h"

block_list::block_list(QWidget *parent=nullptr): Base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_list::createPixmap(){
    block_pixmap = createBlockPixmap(widget_width, widget_height, block_width, block_height, connector, color_back);
    createText(block_pixmap, block_text, block_width);
}


void block_list::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}