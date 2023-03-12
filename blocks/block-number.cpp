
#include <QPainter>
#include "block-number.h"
#include "block-paint.h"

block_number::block_number(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_number::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    edit = createQLineEdit(this, "123", block_width, block_height, read_only);
    edit->show();
}

QPixmap block_number::getPixmap(){
    return grab();
}

bool block_number::isParentBlock(){
    return false;
}

void block_number::insertCode(const QString &code){
    return;
}

QString block_number::toCode(){
    return code_text;
}

QString block_number::whatsThisBlockName(){
    return "number";
}

BlockType block_number::getBlockType(){
    return block_type;
}

BlockShape block_number::getBlockShape(){
    return block_shape;
}
int block_number::getBlockRow() {
    return row;
}

QVector<BlockShape> block_number::getBlockShapes() {
    return QVector<BlockShape>();
}
void block_number::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}