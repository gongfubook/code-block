#ifndef __DND_EVENTS__
#define __DND_EVENTS__

#include <QWidget>
#include <QDropEvent>
#include <QString>
#include <QPoint>
#include <QMap>
#include "block-base.h"


struct Line{
    int start_y;
    int start_x;
    int block_number{0};
    QVector<block_base*> blocks;
};

class CodeListManagement{
public:
    QWidget * parent;
    int widget_height, line_height, start_x;
    QMap<int, Line> lines;
    CodeListManagement(const int widget_height, const int line_height, const int start_x, QWidget * parent = nullptr);
    void dropBlock(QByteArray &itemData, const QPoint &offset);
    block_base* createBlock(const QString &block_name);
    void addBlock(block_base *block, const QPoint& point);
    void moveBlock(block_base *block, const QPoint& point, const QPoint& self_pos);
    int getCurrentLine(const QPoint& point);
    void appendBlockofLine(const int line_number, block_base* block);
    void update(const int line_bumber);
    void inseatUpdateBlock(QByteArray &itemData, const QPoint& point);
};



#endif // __DND_EVENTS__

