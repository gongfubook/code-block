#ifndef __CODE_DISPLAY_WINDOW__
#define __CODE_DISPLAY_WINDOW__


#include <QFrame>
#include <QTextEdit>

class code_display : public QFrame
{
public:
    explicit code_display(QWidget *parent = nullptr);
    void setCodeText(const QString &code);
    QTextEdit * code_edit;

};


#endif // __CODE_DISPLAY_WINDOW__