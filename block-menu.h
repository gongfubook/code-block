
#ifndef __BLOCK_MENU__
#define __BLOCK_MENU__


#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class block_menu : public QFrame
{
public:
    explicit block_menu(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};


#endif // __BLOCK_MENU__