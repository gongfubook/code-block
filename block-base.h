

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
#include <QWidget>
#include <Qcolor>
#include <QPainterPath>

class block : public QWidget{
public:
    uint32_t block_x{20}, block_y{20}, block_width{220}, block_height{50};
    bool block_left{false}, block_right{false}, block_up{false}, block_down{false};
    block(QWidget *parent);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    //背景颜色
    QColor mColorBack = Qt::white;
    //边框颜色
    QColor mColorBorder = Qt::black;
    int font_size{24};
    QPainterPath generate_path();
};


#endif // __BLOCK_BASE__