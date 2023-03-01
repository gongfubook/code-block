#ifndef __DND_EVENTS__
#define __DND_EVENTS__

#include <QWidget>
#include <QDropEvent>
#include <QString>
#include <QPoint>
#include "block-base.h"

struct LineBlocks{
    int block_numbers;
    QVector<BlockShape> shapes;
    QVector<BlockType> types;
};

struct Line{
    int line_number, up, down;
    bool exist;
    LineBlocks blocks;
};

class CodeListManagement{
    int widget_height, line_height;
    QVector<Line> lines;
    CodeListManagement(int height);
    void addBlock(const QByteArray &itemData);
};


block_base* createBlock(
    const QString& block_name,
    const QPoint& point,
    const QPoint& offset,
    QWidget * target,
    const QPoint& self_pos
);




#endif // __DND_EVENTS__

