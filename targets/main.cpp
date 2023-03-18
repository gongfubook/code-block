#include <QApplication>
#include "main-window.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 显示登录界面
    // Login *login = new Login;
    // main_window window;
    // login->show();

    // int ret = app.exec();

    // if (login->isLoginSuccess()) {
    //     window.show();
    //     return app.exec();
    // }

    main_window window;
    window.show();

    return app.exec();
}