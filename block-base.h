

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
#include "block-size.h"

/**
 * 代码块的接口类
*/

class block{
    virtual void createPixmap() = 0;
    virtual void setPixmap(const QPixmap& pixmap) = 0;
    virtual QPixmap getPixmap() = 0;
    virtual void setPoint(const QPoint& point) = 0;
    virtual QPoint getPoint() = 0;
    virtual bool isParentBlock() = 0;
    virtual void insertCode(const QString &code) = 0;
    virtual QString toCode() = 0;
    virtual QString whatsThisBlockName() = 0;
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
    enum Connector left,
    enum Connector right,
    enum Connector up,
    enum Connector down
);

class block_base : public QLabel, block{
public:
    int widget_width{WIDGET_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{male}, block_right{female}, block_up{female}, block_down{male};
    block_base(QWidget *parent);
    virtual void createPixmap();
    virtual void setPixmap(const QPixmap& pixmap);
    virtual QPixmap getPixmap();
    virtual void setPoint(const QPoint& point);
    virtual QPoint getPoint();
    virtual bool isParentBlock();
    virtual void insertCode(const QString &code);
    virtual QString toCode();
    virtual QString whatsThisBlockName();

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