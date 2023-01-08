

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
#include <QWidget>
#include <Qcolor>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPixmap>
#include <QLabel>

#include "block-color.h"

/**
 * 代码块的接口类
*/

class block{
    virtual void createPixmap() = 0;
    virtual void setPixmap(const QPixmap& pixmap) = 0;
    virtual QPixmap getPixmap() = 0;
    virtual void setPoint(const QPoint& point) = 0;
    virtual QPoint getPoint() = 0;
    virtual QString toCode() = 0;
};

enum Connector{
    none = 0,
    male = 1,
    female = 2
};

class block_base : public QLabel, block{
public:
    int widget_width{110}, widget_height{50};
    int block_width{90}, block_height{30};
    QPoint widget_point = QPoint(150, 30);
    QPoint block_point = QPoint(5, 5);
    Connector block_left{male}, block_right{female}, block_up{female}, block_down{male};
    block_base(QWidget *parent);
    virtual void createPixmap();
    virtual void setPixmap(const QPixmap& pixmap);
    virtual QPixmap getPixmap();
    virtual void setPoint(const QPoint& point);
    virtual QPoint getPoint();
    virtual QString toCode();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(VARIABLE_COLOR);
    int font_size{12};
    QPoint startPos;
    QPainterPath block_path;
    QString block_text;
    QPixmap block_pixmap;
    QString code_text;
};


#endif // __BLOCK_BASE__