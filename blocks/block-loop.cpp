#include "block-loop.h"
#include "block-paint.h"

block_loop::block_loop(QWidget *parent=nullptr): block_base(parent){
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

QPixmap block_loop::getPixmap(){
    return grab();
}

bool block_loop::isParentBlock(){
    return false;
}

void block_loop::insertCode(const QString &code){
    return;
}

QString block_loop::toCode(){
    return code_text;
}

QString block_loop::whatsThisBlockName(){
    return "loop";
}

BlockType block_loop::getBlockType(){
    return block_type;
}

BlockShape block_loop::getBlockShape(){
    return block_shape;
}

int block_loop::getBlockRow() {
    return row;
}

QVector<BlockShape> block_loop::getBlockShapes() {
    return withInsideBlocks;
}

void block_loop::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
