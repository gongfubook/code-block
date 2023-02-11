
#include "block-menu.h"


block_menu::block_menu(QWidget *parent)
    : QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));

    block_menu_vbox = new QVBoxLayout(this);
    math_btn = new QPushButton("数学");
    string_btn = new QPushButton("字符串");
    logic_btn = new QPushButton("逻辑");
    loop_btn = new QPushButton("循环");
    function_btn = new QPushButton("函数");
    variable_btn = new QPushButton("变量");
    input_output_btn = new QPushButton("输入/输出");
    list_btn = new QPushButton("数组");
    dict_btn = new QPushButton("字典");

    block_menu_vbox->addWidget(math_btn);
    block_menu_vbox->addWidget(string_btn);
    block_menu_vbox->addWidget(logic_btn);
    block_menu_vbox->addWidget(loop_btn);
    block_menu_vbox->addWidget(function_btn);
    block_menu_vbox->addWidget(variable_btn);
    block_menu_vbox->addWidget(input_output_btn);
    block_menu_vbox->addWidget(list_btn);
    block_menu_vbox->addWidget(dict_btn);
}