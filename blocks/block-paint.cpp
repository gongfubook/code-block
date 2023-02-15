
#include "block-paint.h"
#include <QPainter>
#include <QPen>

QPainterPath createPath(
    int x,
    int y,
    int width,
    int height,
    enum Connector left,
    enum Connector right,
    enum Connector up,
    enum Connector down
){
    QPainterPath path(QPointF(x, y));
    if (up == Connector::none) {
        path.lineTo(x + width, y);
    } else if (up == Connector::female) {
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

    if (right == Connector::none) {
        path.lineTo(x + width, y + height);
    } else if (right == Connector::female) {
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

    if (down == Connector::none) {
        path.lineTo(x, y + height);
    } else if (down == Connector::female) {
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

    if (left == Connector::none) {
        path.lineTo(x, y);
    } else if (left == Connector::female) {
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