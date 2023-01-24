
#include "code-display.h"


code_display::code_display(QWidget *parent)
    : QFrame(parent)
{
    // setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    edit = new QTextEdit(this);
    edit->setMinimumSize(this->size());
    edit->setTabStopDistance(8);
    edit->show();
}

void code_display::setPlainText(const QString &code) {
    edit->setPlainText(code);
}