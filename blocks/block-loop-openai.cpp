#include "block-loop-openai.h"
#include "block-paint.h"

block_loop_openai::block_loop_openai(QWidget *parent) : block_base(parent){
    widget_height = WIDGET_HEIGHT * row;
    // withInsideBlocks.append({block_width, block_height, {none, female, female, none}});
    // block_shape = {block_width, block_height, {male, female, female, male}};
    createPixmap();
    setStyleSheet("background-color:white;");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_loop_openai::createPixmap() {
    block_pixmap = QPixmap(widget_width, widget_height);

    block_pixmap = QPixmap(widget_width, widget_height);
    createWithInsideBlockPixmap(block_pixmap, withInsideBlocks, color_back, row);
    createText(block_pixmap, block_text, block_width);
}

QPixmap block_loop_openai::getPixmap() {
    return grab();
}

bool block_loop_openai::isParentBlock() {
    return true;
}

void block_loop_openai::insertCode(const QString &code) {
    code_text = code;
}

QString block_loop_openai::toCode() {
    // QString insideCode = "";
    // int blockCount = insideBlocks.size();
    // for (int i = 0; i < blockCount; i++) {
    //     insideCode += insideBlocks[i]->toCode();
    // }
    // QString code = QString("for i in range(%1):\n%2").arg(edit->text()).arg(insideCode);
    return "";
}

QString block_loop_openai::whatsThisBlockName() {
    return "loop_openai";
}

BlockType block_loop_openai::getBlockType() {
    return block_type;
}

BlockShape block_loop_openai::getBlockShape() {
    return block_shape;
}

int block_loop_openai::getBlockRow() {
    return row;
}

QVector<BlockShape> block_loop_openai::getBlockShapes() {
    return withInsideBlocks;
}

void block_loop_openai::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
