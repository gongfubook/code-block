
#ifndef __BLOCK_LIST__
#define __BLOCK_LIST__

#include "block-base.h"
#include <QLineEdit>

class block_list: public Base<block_list> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{male}, block_right{none}, block_up{none}, block_down{none};
    block_list(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(ARRAY_COLOR);
    int font_size{12};
    QPoint startPos;
    QString block_text = "创建空数组";
    QPixmap block_pixmap;
    QString code_text = "list()";
};


#endif // __BLOCK_LIST__