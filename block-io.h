
#ifndef __BLOCK_IO__
#define __BLOCK_IO__


#include "block-base.h"
#include <QLineEdit>

class block_print: public block_base {
public:
    int widget_width{140}, widget_height{40};
    int block_width{130}, block_height{30};
    QPoint widget_point = QPoint(150, 30);
    QPoint block_point = QPoint(5, 5);
    Connector block_left{none}, block_right{none}, block_up{female}, block_down{male};
    block_print(QWidget *parent);
    virtual void createPixmap();
    virtual void setPixmap(const QPixmap& pixmap);
    virtual QPixmap getPixmap();
    virtual void setPoint(const QPoint& point);
    virtual QPoint getPoint();
    virtual QString toCode();
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
    QLineEdit* edit;
};


#endif // __BLOCK_IO__