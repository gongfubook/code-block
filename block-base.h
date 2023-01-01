

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
#include <QWidget>
#include <Qcolor>

class block : public QWidget{
public:
    uint32_t width{90}, height{30};
    bool left{false}, right{false}, up{false}, down{false};
    block(){setAcceptDrops(true);}
    explicit block(QWidget *parent=nullptr): QWidget(parent){};
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    //背景颜色
    QColor mColorBack=Qt::white;
    //电池边框颜色
    QColor mColorBorder=Qt::black;
    //电池柱颜色
    QColor mColorPower=Qt::green;
    //电池短缺颜色
    QColor mColorWarning=Qt::red;
    //电量0-100
    int mPowerLevel=60;
    //电量低警示阈值
    int myWarnLevrl=20;
};


#endif // __BLOCK_BASE__