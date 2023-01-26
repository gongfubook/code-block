
#include "code-display.h"
#include <QVBoxLayout>
#include <QLabel>


code_display::code_display(QWidget *parent)
    : QFrame(parent)
{
    setMaximumWidth(350);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    QLabel * code_label = new QLabel("代码：");
    code_edit = new QTextEdit(this);
    code_edit->setMaximumSize(330, 300);
    code_edit->setMinimumSize(330, 300);
    code_edit->setTabStopDistance(8);
    vboxLayout->addWidget(code_label);
    vboxLayout->addWidget(code_edit);
    
}

void code_display::setCodeText(const QString &code) {
    code_edit->setPlainText(code);
}
