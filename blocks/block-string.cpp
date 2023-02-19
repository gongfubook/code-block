#include "block-string.h"
#include "block-paint.h"

block_string::block_string(QWidget *parent=nullptr, bool read_only=true): Base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_string::createPixmap(){
    block_pixmap = createBlockPixmap(widget_width, widget_height, block_width, block_height, connector, color_back);
    edit = createQLineEdit(this, "Hello", block_width, block_height, read_only);
    edit->show();

}

QString block_string::get_edit_text(){
    return "\"" + edit->text() + "\"";
}

void block_string::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}