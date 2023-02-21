#ifndef __DND_EVENTS__
#define __DND_EVENTS__

#include <QWidget>
#include <QDropEvent>
#include <QString>
#include <QPoint>
#include "block-base.h"

block_base* createBlock(
    const QString& block_name,
    const QPoint& point,
    const QPoint& offset,
    QWidget * target
);




#endif // __DND_EVENTS__

