
#include "block-function.h"


#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QLabel>



block_function::block_function(QWidget *parent=nullptr, bool read_only=true): block_base(parent), read_only(read_only){
    resize(widget_width, widget_height); 
    setAcceptDrops(true);  
    createPixmap();
    setStyleSheet("background:transparent");
    setAttribute(Qt::WA_DeleteOnClose);
}

void block_function::createPixmap(){
    block_pixmap = QPixmap(widget_width, widget_height);
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    painter.setPen(color_back);
    painter.setBrush(color_back);
    block_path = createPath(block_point.x() + BLOCK_FUNCTION_LEFT_WIDTH, block_point.y(), block_width, BLOCK_HEIGHT, block_left_up, block_right_up, block_up_up, block_down_up);
    painter.drawPath(block_path);
    block_path = createPath(block_point.x(), block_point.y(), BLOCK_FUNCTION_LEFT_WIDTH, block_height, block_left_left, block_right_left, block_up_left, block_down_left);
    painter.drawPath(block_path);
    block_path = createPath(block_point.x() + BLOCK_FUNCTION_LEFT_WIDTH, block_point.y() + BLOCK_HEIGHT * 2, block_width, BLOCK_HEIGHT, block_left_down, block_right_down, block_up_down, block_down_down);
    painter.drawPath(block_path);
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(font_size);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);

    painter.setFont(font);
    QFontMetrics fm = painter.fontMetrics();
    int width_text = fm.horizontalAdvance(block_text);
    painter.drawText(block_point.x() + 5, (block_height - font_size) + (block_height - font_size) / 2, block_text);
    edit = new QLineEdit(this);
    edit->setMinimumWidth(block_width - (block_point.x() + 5 + width_text));
    edit->setMaximumWidth(block_width - (block_point.x() + 5 + width_text));
    edit->setMinimumHeight(BLOCK_HEIGHT - 5);
    edit->setMaximumHeight(BLOCK_HEIGHT - 5);
    edit->move(block_point.x() + 5 + width_text, block_point.y() + 3);
    edit->setText(block_text);
    edit->setReadOnly(read_only);
    edit->show();
    painter.end();
}

void block_function::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
