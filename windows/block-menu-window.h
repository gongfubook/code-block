
#ifndef __BLOCK_MENU_WINDOW__
#define __BLOCK_MENU_WINDOW__


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
    QPushButton *input_output_btn;
    QPushButton *list_btn;
    QPushButton *dict_btn;
};


#endif // __BLOCK_MENU_WINDOW__