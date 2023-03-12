#include "block-dict.h"
#include "block-paint.h"

block_dict::block_dict(QWidget *parent=nullptr): block_base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_dict::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    createText(block_pixmap, block_text, block_width);
}

QPixmap block_dict::getPixmap(){
    return grab();
}

bool block_dict::isParentBlock(){
    return false;
}

void block_dict::insertCode(const QString &code){
    return;
}

QString block_dict::toCode(){
    return code_text;
}

QString block_dict::whatsThisBlockName(){
    return "dict";
}

BlockType block_dict::getBlockType(){
    return block_type;
}

BlockShape block_dict::getBlockShape(){
    return block_shape;
}
int block_dict::getBlockRow() {
    return row;
}

QVector<BlockShape> block_dict::getBlockShapes() {
    return QVector<BlockShape>();
}
void block_dict::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}