#ifndef __CODE_DISPLAY__
#define __CODE_DISPLAY__


#include <QFrame>
#include <QTextEdit>

class code_display : public QFrame
{
public:
    explicit code_display(QWidget *parent = nullptr);
    void setPlainText(const QString &code);
    QTextEdit * edit;

};


#endif // __CODE_DISPLAY__