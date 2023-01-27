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
#include "output-display.h"
#include "block-menu.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class main_window : public QWidget
{
    Q_OBJECT;
public:
    explicit main_window(QWidget *parent = nullptr);
    ~main_window() Q_DECL_OVERRIDE;

public slots:
    void click_compiler();
    void click_run();
    void click_clean();

private:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *main_menu;
    QHBoxLayout *code_block_windows;
    block_menu *block_menu_window;
    block_list *block_list_window;
    code_list *code_list_window;
    code_display *code_display_window;
    output_display *output_display_window;
    QString code_str;
    QString code_path;
    QString code_file;
    QString exe_file;
};


#endif // __MAIN_WINDOW__