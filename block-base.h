

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

QPainterPath createPath(
    int x,
    int y,
    int width,
    int height,
    Connector left,
    Connector right,
    Connector up,
    Connector down
);

class block_base : public QLabel, block{
public:
    uint32_t block_x{20}, block_y{20}, block_width{220}, block_height{50};
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
    // void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    // void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    // void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(VARIABLE_COLOR);
    int font_size{24};
    QPoint startPos;
    QPainterPath block_path;
    QString block_text;
    QPixmap block_pixmap;
    QString code_text;

};


#endif // __BLOCK_BASE__