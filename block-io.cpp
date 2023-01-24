
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
    setAttribute(Qt::WA_TranslucentBackground);
    // setStyleSheet("background-color:red;");
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
    int width_text = fm.horizontalAdvance(block_text);
    painter.drawText(block_point.x() + 5, (block_height - font_size) + (block_height - font_size) / 2, block_text);
    edit = new QLineEdit(this);
    edit->setMinimumWidth(block_width - (block_point.x() + 5 + width_text));
    edit->setMaximumWidth(block_width - (block_point.x() + 5 + width_text));
    edit->setMinimumHeight(block_height - 5);
    edit->setMaximumHeight(block_height - 5);
    edit->move(block_point.x() + 5 + width_text, block_point.y() + 3);
    edit->setText("你好，世界！");
    edit->setReadOnly(read_only);
    edit->show();
    painter.end();
}

void block_print::setPixmap(const QPixmap& pixmap){
    block_pixmap = pixmap;
}

QPixmap block_print::getPixmap(){
    return block_pixmap;
}

void block_print::setPoint(const QPoint& point){
    move(point);
}

QPoint block_print::getPoint(){
    return pos();
}
bool block_print::isParentBlock(){
    return false;
}

QString block_print::toCode(){
    return "\tprintf(\"" + edit->text() + "\");\n";
}

QString block_print::whatsThisBlockName(){
    return "output";
}

void block_print::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(QRect(0, 0, block_pixmap.width(), block_pixmap.height()), block_pixmap);
}
