#ifndef __BLOCK_PAINT__
#define __BLOCK_PAINT__

#include <QPainterPath>
#include "block-types.h"
#include <QPainter>



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
    QPainter &painter,
    QString block_text,
    int block_width,
    enum TextAlign aligen
);


/**
 * 绘制块
*/
QPixmap createBlockPixmap(
    const int widget_width, 
    const int widget_height,
    const int block_width, 
    const int block_height,
    const BlockConnector& connector,
    const int block_color
);


#endif // __BLOCK_PAINT__