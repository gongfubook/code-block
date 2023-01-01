
#include <QApplication>
#include <QHBoxLayout>

#include "block-list.h"
#include "code-list.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget mainWidget;
    mainWidget.setMinimumWidth(1080);
    mainWidget.setMinimumHeight(750);

    QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
    horizontalLayout->addWidget(new block_list);
    horizontalLayout->addWidget(new code_list);

    mainWidget.setWindowTitle(QObject::tr("Code Block"));
    mainWidget.show();

    return app.exec();
}
