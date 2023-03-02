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
    QWidget * parent;
    int widget_height, line_height;
    QVector<Line> lines;
    CodeListManagement(const int widget_height, const int line_height, QWidget * parent = nullptr);
    void createBlock(QByteArray &itemData);
    void addBlock(block_base *block, const QPoint& point, const QPoint& offset, QWidget * target);
    void moveBlock(block_base *block, const QPoint& point, const QPoint& offset, QWidget * target, const QPoint& self_pos);
    Line getCurrentLine(const QPoint& point);
};


block_base* createBlock(
    const QString& block_name,
    const QPoint& point,
    const QPoint& offset,
    QWidget * target,
    const QPoint& self_pos
);




#endif // __DND_EVENTS__

