#include "block-function.h"
#include "block-paint.h"


block_function::block_function(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_function::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createWithInsideBlockPixmap(block_pixmap,withInsideBlocks, color_back, row);
    // createText(block_pixmap, block_text, block_width, TextAlign::left);
    edit = createQLineEdit(this, "函数1", block_width, block_height, read_only);
    edit->show();
}

QPixmap block_function::getPixmap(){
    return grab();
}

bool block_function::isParentBlock(){
    return false;
}

void block_function::insertCode(const QString &code){
    return;
}

QString block_function::toCode(){
    return code_text;
}

QString block_function::whatsThisBlockName(){
    return "function";
}

BlockType block_function::getBlockType(){
    return block_type;
}

void block_function::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
