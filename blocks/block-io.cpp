#include "block-io.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>
#include "block-paint.h"

block_print::block_print(QWidget *parent=nullptr): Base(parent){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_print::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    createBlockPixmap(block_pixmap, block_shape, color_back);
    createText(block_pixmap, block_text, block_width);
}

void block_print::insertCode(const QString &code) {
    QString code_text = code_text_begin + code + code_text_end;
}

void block_print::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
