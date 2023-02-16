#include "block-io.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>

block_print::block_print(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_print::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    painter.setPen(Qt::white);
    painter.setBrush(color_back);
    block_path = createPath(block_point.x(), block_point.y(), block_width, block_height, block_left, block_right, block_up, block_down);
    painter.drawPath(block_path);
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(font_size);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);

    painter.setFont(font);
    QFontMetrics fm = painter.fontMetrics();
    painter.drawText(block_point.x() + 5, (block_height - font_size) + (block_height - font_size) / 2, block_text);
    painter.end();
}

void block_print::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
