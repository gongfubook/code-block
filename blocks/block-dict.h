
#ifndef __BLOCK_DICT__
#define __BLOCK_DICT__


#include "block-base.h"


class block_dict: public Base<block_dict> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{male}, block_right{none}, block_up{none}, block_down{none};
    block_dict(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(DICT_COOLOR);
    int font_size{12};
    QPoint startPos;
    QString block_text = "创建空字典";
    QPixmap block_pixmap;
    QString code_text = "dict()";
};


#endif // __BLOCK_ARRAY__