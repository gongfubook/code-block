#include "block-variable.h"
#include "block-paint.h"

block_variable::block_variable(QWidget *parent=nullptr, bool read_only=true): Base(parent), read_only(read_only){
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

QString block_variable::get_edit_text(){
    return edit->text();
}

void block_variable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}