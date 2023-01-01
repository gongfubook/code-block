

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
#include <QWidget>
#include <Qcolor>
#include <QPainterPath>

class block : public QWidget{
public:
    uint32_t x{20}, y{20}, width{220}, height{50};
    bool left{false}, right{false}, up{false}, down{false};
    block(QWidget *parent);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    //背景颜色
    QColor mColorBack = Qt::white;
    //边框颜色
    QColor mColorBorder = Qt::black;
    QPainterPath generate_path();
};


#endif // __BLOCK_BASE__