#ifndef __OUTPUT_WINDOW__
#define __OUTPUT_WINDOW__


#include <QFrame>
#include <QTextEdit>

class output_display_window : public QFrame
{
public:
    explicit output_display_window(QWidget *parent = nullptr);
    void setOutputText(const QString &output);
    QTextEdit * output_edit;

};


#endif // __OUTPUT_WINDOW__