#include "block-string.h"
#include "block-paint.h"

block_string::block_string(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_string::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    edit = createQLineEdit(this, "Hello", block_width, block_height, read_only);
    edit->show();

}

QPixmap block_string::getPixmap(){
    return grab();
}

bool block_string::isParentBlock(){
    return false;
}

void block_string::insertCode(const QString &code){
    return;
}

QString block_string::toCode(){
    return code_text;
}

QString block_string::whatsThisBlockName(){
    return "string";
}

BlockType block_string::getBlockType(){
    return block_type;
}

void block_string::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}