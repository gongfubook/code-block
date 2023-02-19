#include "block-loop.h"
#include "block-paint.h"

block_loop::block_loop(QWidget *parent=nullptr): Base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background-color:white;");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_loop::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createWithInsideBlockPixmap(block_pixmap,withInsideBlocks, color_back, row);
    createText(block_pixmap, block_text, block_width);
}

void block_loop::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
