
#include "block-paint.h"
#include <QPainter>
#include <QPen>
#include "block-size.h"
#include "block-text-style.h"
#include "block-color.h"

QPainterPath createPath(
    int x,
    int y,
    int width,
    int height,
    const BlockConnector& connector
){
    QPainterPath path(QPoint(x, y));
    if (connector.up == Connector::none) {
        path.lineTo(x + width, y);
    } else if (connector.up == Connector::female) {
        path.lineTo(x + 30, y);
        path.lineTo(x + 35, y + 5);
        path.lineTo(x + 40, y);
        path.lineTo(x + width, y);
    } else {
        path.lineTo(x + 30, y);
        path.lineTo(x + 35, y - 5);
        path.lineTo(x + 40, y);
        path.lineTo(x + width, y);
    }

    if (connector.right == Connector::none) {
        path.lineTo(x + width, y + height);
    } else if (connector.right == Connector::female) {
        path.lineTo(x + width, y + 10);
        path.lineTo(x + width - 5, y + 5);
        path.lineTo(x + width - 5, y + 25);
        path.lineTo(x + width, y + 20);
        path.lineTo(x + width, y + height);
    } else {
        path.lineTo(x + width, y + 10);
        path.lineTo(x + width + 5, y + 5);
        path.lineTo(x + width + 5, y + 25);
        path.lineTo(x + width, y + 20);
        path.lineTo(x + width, y + height);
    }

    if (connector.down == Connector::none) {
        path.lineTo(x, y + height);
    } else if (connector.down == Connector::female) {
        path.lineTo(x + 40, y + height);
        path.lineTo(x + 35, y - 5 + height);
        path.lineTo(x + 30, y + height);
        path.lineTo(x, y + height);
    } else {
        path.lineTo(x + 40, y + height);
        path.lineTo(x + 35, y + 5 + height);
        path.lineTo(x + 30, y + height);
        path.lineTo(x, y + height);
    }

    if (connector.left == Connector::none) {
        path.lineTo(x, y);
    } else if (connector.left == Connector::female) {
        path.lineTo(x, y + 20);
        path.lineTo(x + 5, y + 25);
        path.lineTo(x + 5, y + 5);
        path.lineTo(x, y + 10);
        path.lineTo(x, y);
    } else {
        path.lineTo(x, y + 20);
        path.lineTo(x - 5, y + 25);
        path.lineTo(x - 5, y + 5);
        path.lineTo(x, y + 10);
        path.lineTo(x, y);
    }
    return path;
}

void createText(
    QPixmap &block_pixmap,
    const QString &block_text,
    int block_width,
    enum TextAlign aligen
){
    QPainter painter(&block_pixmap);
    QFont font;
    font.setFamily(BLOCK_TEXT_STYLE);
    font.setPointSize(BLOCK_TEXT_SIZE);
    font.setLetterSpacing(QFont::AbsoluteSpacing, BLOCK_TEXT_LETTER_SPACING);
    painter.setFont(font);
    painter.setPen(rgbColor(BLOCK_TEXT_COLOR));
    int text_point_y = (BLOCK_HEIGHT - BLOCK_TEXT_SIZE) + (int)((BLOCK_HEIGHT - BLOCK_TEXT_SIZE) / 2.0);
    if (aligen == TextAlign::left) {
        painter.drawText(BLOCK_X, text_point_y, block_text);
        return;
    }
    QFontMetrics fm = painter.fontMetrics();
    int text_width = fm.horizontalAdvance(block_text);
    if (aligen == TextAlign::center) {
        painter.drawText(BLOCK_X + (int)((block_width - text_width) / 2.0), text_point_y, block_text);
        return;
    }
    if (aligen == TextAlign::right) {
        painter.drawText(BLOCK_X + (block_width - text_width),text_point_y, block_text);
        return;
    }
}

void createBlockPixmap(
    QPixmap &block_pixmap,
    const BlockShape& block,
    const int block_color
){
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    QColor color_back = rgbColor(block_color);
    painter.setPen(color_back);
    painter.setBrush(color_back);
    QPainterPath block_path = createPath(BLOCK_X, BLOCK_Y, block.block_width, block.block_height, block.connector);
    painter.drawPath(block_path);
}

void createWithInsideBlockPixmap(
    QPixmap &block_pixmap,
    const QVector<BlockShape> &withInsideBlocks,
    const int block_color,
    const int row
){
    block_pixmap.fill(Qt::transparent);
    QPainter painter(&block_pixmap);
    QColor color_back = rgbColor(block_color);
    painter.setPen(color_back);
    painter.setBrush(color_back);
    QPainterPath block_path = createPath(BLOCK_X, BLOCK_Y, withInsideBlocks[0].block_width, withInsideBlocks[0].block_height * row, withInsideBlocks[0].connector);
    painter.drawPath(block_path);
    block_path = createPath(BLOCK_X + BLOCK_LEFT_WIDTH, BLOCK_Y,  withInsideBlocks[1].block_width, withInsideBlocks[1].block_height, withInsideBlocks[1].connector);
    painter.drawPath(block_path);
    block_path = createPath(BLOCK_X + BLOCK_LEFT_WIDTH, BLOCK_Y + BLOCK_HEIGHT * (row - 1), withInsideBlocks[2].block_width, withInsideBlocks[2].block_height, withInsideBlocks[2].connector);
    painter.drawPath(block_path);
}

QLineEdit* createQLineEdit(
    QWidget *parent,
    const QString& text,
    const int block_width,
    const int block_height,
    const bool read_only
){
    QLineEdit* edit = new QLineEdit(parent);
    edit->setStyleSheet("QLineEdit{border-width:0;border-style:outset;background-color:white;border-radius:10px;}");
    edit->setMinimumWidth(20);
    edit->setMaximumWidth(block_width - 10);
    edit->setMinimumHeight(block_height - 10);
    edit->setMaximumHeight(block_height - 10);
    edit->move((block_width - edit->width()) / 2, 11);
    edit->setText(text);
    edit->setReadOnly(read_only);
    return edit;
}
