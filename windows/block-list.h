#ifndef __BLOCK_LIST__
#define __BLOCK_LIST__

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class block_class_list : QWidget {
    Q_OBJECT;
public:
    explicit block_class_list(QWidget *parent = nullptr);
    QVBoxLayout *inner_block_list;
    void addWidget(QWidget * widget);
    void block_class_list_show();
    void block_class_list_hide();
};

class block_list : public QFrame
{
    Q_OBJECT;
public:
    explicit block_list(QWidget *parent = nullptr);

    block_class_list *code_number_list;
    block_class_list *code_string_list;
    block_class_list *code_logic_list;
    block_class_list *code_loop_list;
    block_class_list *code_function_list;
    block_class_list *code_variable_list;
    block_class_list *code_input_output_list;
    block_class_list *code_list_list;
    block_class_list *code_dict_list;

public slots:
    void show_number();
    void show_string();
    void show_logic();
    void show_loop();
    void show_function();
    void show_variable();
    void show_input_output();
    void show_list();
    void show_dict();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;


};


#endif // __BLOCK_LIST__