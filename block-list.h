#ifndef __BLOCK_LIST__
#define __BLOCK_LIST__

#include <QFrame>

#include "block-io.h"
#include "block-function.h"
#include "block-number.h"
#include "block-string.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class block_list : public QFrame
{
    Q_OBJECT;
public:
    explicit block_list(QWidget *parent = nullptr);
    block_string *b_str;
    block_print *b_print;
    block_function *b_function;
    block_number *b_number;

public slots:
    void show_number();
    void show_string();
    void show_logic();
    void show_loop();
    void show_function();
    void show_variable();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;


};


#endif // __BLOCK_LIST__