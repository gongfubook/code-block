#ifndef __BLOCK_LIST__
#define __BLOCK_LIST__

#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class block_list : public QFrame
{
public:
    explicit block_list(QWidget *parent = nullptr);
    QPoint startPos;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // __BLOCK_LIST__