#ifndef __OUTPUT_WINDOW__
#define __OUTPUT_WINDOW__


#include <QFrame>
#include <QTextEdit>

class output_display : public QFrame
{
public:
    explicit output_display(QWidget *parent = nullptr);
    void setOutputText(const QString &output);
    QTextEdit * output_edit;

};


#endif // __OUTPUT_WINDOW__