
#ifndef __BLOCK_NUMBER__
#define __BLOCK_NUMBER__


#include "block-base.h"
#include <QLineEdit>

class block_number: public Base<block_number> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{male}, block_right{none}, block_up{none}, block_down{none};
    bool read_only;
    block_number(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(MATH_COLOR);
    int font_size{12};
    QPoint startPos;
    QString block_text = "";
    QPixmap block_pixmap;
    QString code_text;
    QLineEdit* edit;
};


#endif // __BLOCK_NUMBER__