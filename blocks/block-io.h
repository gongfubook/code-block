
#ifndef __BLOCK_IO__
#define __BLOCK_IO__


#include "block-base.h"
#include <QLineEdit>

class block_print: public Base<block_print> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockConnector connector{none, female, female, male};
    int color_back = FUNCTION_COLOR;
    QString block_text = "输出";
    QPixmap block_pixmap;
    QString code_text;
    block_print(QWidget *parent);
    virtual void createPixmap();
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#endif // __BLOCK_IO__