#ifndef __BLOCK_PAINT__
#define __BLOCK_PAINT__

#include <QPainterPath>
#include "block-types.h"

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



#endif // __BLOCK_PAINT__