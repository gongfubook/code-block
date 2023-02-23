#include "block-logic.h"
#include "block-paint.h"

block_logic::block_logic(QWidget *parent=nullptr): block_base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background-color:white;");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_logic::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createWithInsideBlockPixmap(block_pixmap,withInsideBlocks, color_back, row);
    createText(block_pixmap, block_text, block_width);
}

QPixmap block_logic::getPixmap(){
    return grab();
}

bool block_logic::isParentBlock(){
    return false;
}

void block_logic::insertCode(const QString &code){
    return;
}

QString block_logic::toCode(){
    return code_text;
}

QString block_logic::whatsThisBlockName(){
    return "logic";
}

BlockType block_logic::getBlockType(){
    return block_type;
}

BlockShape block_logic::getBlockShape(){
    return block_shape;
}

void block_logic::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
