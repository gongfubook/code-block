#ifndef __CODE_LIST_WINDOW__
#define __CODE_LIST_WINDOW__


#include <QFrame>
#include "dnd-events.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class code_list_window : public QFrame
{
public:
    explicit code_list_window(QWidget *parent = nullptr);
    int widget_height{400}, widget_width{200};
    int line_height{32};
    int line_start_x{30};
    CodeListManagement *code_list_manage;
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};


#endif // __CODE_LIST_WINDOW__