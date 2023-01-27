
#ifndef __BLOCK_MENU__
#define __BLOCK_MENU__


#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

class block_menu : public QFrame
{
    Q_OBJECT;
public:
    explicit block_menu(QWidget *parent = nullptr);
    QVBoxLayout *block_menu_vbox;
    QPushButton *math_btn;
    QPushButton *string_btn;
    QPushButton *logic_btn;
    QPushButton *loop_btn;
    QPushButton *function_btn;
    QPushButton *variable_btn;
};


#endif // __BLOCK_MENU__