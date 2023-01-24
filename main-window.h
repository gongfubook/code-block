#ifndef __MAIN_WINDOW__
#define __MAIN_WINDOW__

#include <QHBoxLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

#include "block-list.h"
#include "code-list.h"
#include "main-window.h"
#include "code-display.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class main_window : public QWidget
{
    Q_OBJECT;
public:
    explicit main_window(QWidget *parent = nullptr);

public slots:
    void click_compiler();
    void click_run();
    void click_clean();

private:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *horizontalLayout1;
    QHBoxLayout *horizontalLayout2;
    block_list *block_list_window;
    code_list *code_list_window;
    code_display *code_display_window;
    QString code_str;
};


#endif // __MAIN_WINDOW__