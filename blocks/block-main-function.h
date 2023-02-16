

#ifndef __BLOCK_MAIN_FUNCTION__
#define __BLOCK_MAIN_FUNCTION__


#include "block-function.h"
#include <QLineEdit>

class block_main_function: public Base<block_function> {
public:
    int widget_width{WIDGET_FUNCTION_WIDTH}, widget_height{WIDGET_FUNCTION_HEIGHT};
    int block_width{BLOCK_FUNCTION_WIDTH}, block_height{BLOCK_FUNCTION_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left_up{none}, block_right_up{none}, block_up_up{none}, block_down_up{male};
    Connector block_left_left{none}, block_right_left{none}, block_up_left{none}, block_down_left{none};
    Connector block_left_down{none}, block_right_down{none}, block_up_down{female}, block_down_down{none};
    bool read_only;
    block_main_function(QWidget *parent, bool read_only);
    
    virtual void createPixmap();
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(FUNCTION_COLOR);
    int font_size{12};
    QPixmap block_pixmap;
    QString block_text = "主函数";
    QString code_text_begin = "int main(int argc, char* argv[]) {\n";
    QString code_text_end = "\treturn 0;\n}\n";
    QString code_text;
};


#endif // __BLOCK_MAIN_FUNCTION__