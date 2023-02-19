#ifndef __BLOCK_PAINT__
#define __BLOCK_PAINT__

#include <QPainterPath>
#include "block-types.h"
#include <QPainter>
#include <QLineEdit>
#include <QVector>

/**
 * 文本对齐位置
*/
enum TextAlign{
    center = 0,
    left = 1,
    right = 2
};

/**
 * 绘制路径
*/
QPainterPath createPath(
    int x,
    int y,
    int width,
    int height,
    enum Connector left,
    enum Connector right,
    enum Connector up,
    enum Connector down
);



/**
 * 在代码块上绘制文字
*/
void createText(
    QPixmap &block_pixmap,
    QString block_text,
    int block_width,
    enum TextAlign aligen = TextAlign::center
);


/**
 * 绘制块
*/
void createBlockPixmap(
    QPixmap &block_pixmap,
    const BlockShape& block,
    const int block_color
);


/**
 * 绘制C形状块
*/
void createWithInsideBlockPixmap(
    QPixmap &block_pixmap,
    const QVector<BlockShape> &withInsideBlocks,
    const int block_color
);


/**
 * 创建一个输入框
*/
QLineEdit* createQLineEdit(
    QWidget *parent,
    const QString& text,
    const int block_width,
    const int block_height,
    const bool read_only
);


#endif // __BLOCK_PAINT__