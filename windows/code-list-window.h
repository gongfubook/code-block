#ifndef __CODE_LIST_WINDOW__
#define __CODE_LIST_WINDOW__


#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class code_list : public QFrame
{
public:
    explicit code_list(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // __CODE_LIST_WINDOW__