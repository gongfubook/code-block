#ifndef __DND_EVENTS__
#define __DND_EVENTS__

#include <QWidget>
#include <QDropEvent>
#include <QString>
#include <QPoint>
#include <QMap>
#include "block-base.h"


struct Line{
    int strart_y;
    QVector<block_base*> blocks;
};

class CodeListManagement{
public:
    QWidget * parent;
    int widget_height, line_height;
    QMap<int, Line> lines;
    CodeListManagement(const int widget_height, const int line_height, QWidget * parent = nullptr);
    void dropBlock(QByteArray &itemData, const QPoint &offset);
    block_base* createBlock(const QString &block_name);
    void addBlock(block_base *block, const QPoint& point);
    void moveBlock(block_base *block, const QPoint& point, const QPoint& self_pos);
    Line getCurrentLine(const QPoint& point);
    void update(const int line_bumber);
};



#endif // __DND_EVENTS__

