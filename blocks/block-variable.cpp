#include "block-variable.h"
#include "block-paint.h"

block_variable::block_variable(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_variable::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    edit = createQLineEdit(this, "", block_width, block_height, read_only);
    edit->show();
}

QPixmap block_variable::getPixmap(){
    return grab();
}

bool block_variable::isParentBlock(){
    return false;
}

void block_variable::insertCode(const QString &code){
    return;
}

QString block_variable::toCode(){
    return code_text;
}

QString block_variable::whatsThisBlockName(){
    return "variable";
}

BlockType block_variable::getBlockType(){
    return block_type;
}

BlockShape block_variable::getBlockShape(){
    return block_shape;
}

int block_variable::getBlockRow() {
    return row;
}

QVector<BlockShape> block_variable::getBlockShapes() {
    return QVector<BlockShape>();
}

void block_variable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}