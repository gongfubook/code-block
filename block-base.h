

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

template<typename T>
class Base{
public:
    int get_a(){
        T* self = static_cast<T*>(this);
        return self->a;
    }
};

class block_base : public QLabel, block{
public:
    int widget_width{WIDGET_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{male}, block_right{female}, block_up{female}, block_down{male};
    block_base(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual void setPixmap(const QPixmap& pixmap) Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual void setPoint(const QPoint& point) Q_DECL_OVERRIDE;
    virtual QPoint getPoint() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;
    virtual bool up();

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