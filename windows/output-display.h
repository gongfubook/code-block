#ifndef __OUTPUT_DISPLAY__
#define __OUTPUT_DISPLAY__


#include <QFrame>
#include <QTextEdit>

class output_display : public QFrame
{
public:
    explicit output_display(QWidget *parent = nullptr);
    void setOutputText(const QString &output);
    QTextEdit * output_edit;

};


#endif // __OUTPUT_DISPLAY__