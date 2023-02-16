
#ifndef __BLOCK_FUNCTION__
#define __BLOCK_FUNCTION__


#include "block-base.h"
#include <QLineEdit>

class block_function: public Base<block_function> {
public:
    int widget_width{WIDGET_FUNCTION_WIDTH}, widget_height{WIDGET_FUNCTION_HEIGHT};
    int block_width{BLOCK_FUNCTION_WIDTH}, block_height{BLOCK_FUNCTION_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left_up{none}, block_right_up{none}, block_up_up{none}, block_down_up{male};
    Connector block_left_left{none}, block_right_left{none}, block_up_left{none}, block_down_left{none};
    Connector block_left_down{none}, block_right_down{none}, block_up_down{female}, block_down_down{none};
    bool read_only;
    block_function(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(FUNCTION_COLOR);
    int font_size{12};
    QPoint startPos;
    QString block_text = "函数";
    QPixmap block_pixmap;
    QString code_text;
    QLineEdit* edit;
};


#endif // __BLOCK_FUNCTION__