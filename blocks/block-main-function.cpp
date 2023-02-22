#include "block-main-function.h"
#include "block-paint.h"
#include <QDebug>


block_main_function::block_main_function(QWidget *parent=nullptr): block_base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose, true);
}

void block_main_function::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createWithInsideBlockPixmap(block_pixmap,withInsideBlocks, color_back, row);
    createText(block_pixmap, block_text, block_width);
}

QPixmap block_main_function::getPixmap(){
    return grab();
}

bool block_main_function::isParentBlock(){
    return false;
}

void block_main_function::insertCode(const QString &code){
    return;
}

QString block_main_function::toCode(){
    return code_text;
}

QString block_main_function::whatsThisBlockName(){
    return "main_function";
}

BlockType block_main_function::getBlockType(){
    return block_type;
}

void block_main_function::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}

