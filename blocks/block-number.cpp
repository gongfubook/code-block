
#include <QPainter>
#include "block-number.h"
#include "block-paint.h"

block_number::block_number(QWidget *parent=nullptr, bool read_only=true): Base(parent), read_only(read_only){
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

QString block_number::get_edit_text(){
    return edit->text();
}

void block_number::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}