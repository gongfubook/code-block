#include "block-set-variable.h"
#include "block-paint.h"
#include "block-types.h"
#include "block-text-style.h"

block_set_variable::block_set_variable(QWidget *parent, bool read_only) : block_base(parent), read_only(read_only) {
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_set_variable::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    createText(block_pixmap, "设置变量", block_width, TextAlign::center);
    edit = createQLineEdit(this, "", block_width, block_height, read_only);
    edit->setAlignment(Qt::AlignLeft);
    edit->show();
    // createPluggableBlock(block_pixmap, QPointF(5, BLOCK_HEIGHT / 2), BlockConnector{none, male, none, none}, color_back);
}

QPixmap block_set_variable::getPixmap(){
    return grab();
}

bool block_set_variable::isParentBlock(){
    return false;
}

void block_set_variable::insertCode(const QString &code){
    return;
}

QString block_set_variable::toCode(){
    return code_text;
}

QString block_set_variable::whatsThisBlockName(){
    return "set_variable";
}

BlockType block_set_variable::getBlockType(){
    return block_type;
}

BlockShape block_set_variable::getBlockShape(){
    return block_shape;
}

int block_set_variable::getBlockRow() {
    return row;
}

QVector<BlockShape> block_set_variable::getBlockShapes() {
    return QVector<BlockShape>();
}

void block_set_variable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}