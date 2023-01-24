#ifndef __CODE_DISPLAY__
#define __CODE_DISPLAY__


#include <QFrame>
#include <QTextEdit>

class code_display : public QFrame
{
public:
    explicit code_display(QWidget *parent = nullptr);
    void setCodeText(const QString &code);
    void setOutputText(const QString &output);
    QTextEdit * code_edit;
    QTextEdit * output_edit;

};


#endif // __CODE_DISPLAY__