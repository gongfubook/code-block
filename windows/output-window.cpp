
#include "output-display.h"
#include <QVBoxLayout>
#include <QLabel>


output_display::output_display(QWidget *parent)
    : QFrame(parent)
{
    // setMaximumWidth(350);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    QLabel * output_label = new QLabel("输出：");
    output_edit = new QTextEdit(this);
    // output_edit->setMaximumSize(330, 300);
    // output_edit->setMinimumSize(330, 300);
    vboxLayout->addWidget(output_label);
    vboxLayout->addWidget(output_edit);
    
}


void output_display::setOutputText(const QString &output) {
    output_edit->setPlainText(output);
}