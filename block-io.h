
#ifndef __BLOCK_IO__
#define __BLOCK_IO__


#include "block-base.h"
#include <QLineEdit>

class block_print: public block_base {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{none}, block_right{female}, block_up{female}, block_down{male};
    bool read_only;
    block_print(QWidget *parent, bool read_only);
    virtual void createPixmap();
    virtual void setPixmap(const QPixmap& pixmap);
    virtual QPixmap getPixmap();
    virtual void setPoint(const QPoint& point);
    virtual QPoint getPoint();
    virtual bool isParentBlock();
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(FUNCTION_COLOR);
    int font_size{12};
    QPoint startPos;
    QPainterPath block_path;
    QString block_text = "输出";
    QPixmap block_pixmap;
    QString code_text;
};


#endif // __BLOCK_IO__