
#ifndef __BLOCK_VARIABLE__
#define __BLOCK_VARIABLE__


#include "block-base.h"
#include <QLineEdit>

class block_variable: public block_base {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    QPoint block_point = QPoint(BLOCK_X, BLOCK_Y);
    Connector block_left{none}, block_right{male}, block_up{none}, block_down{none};
    bool read_only;
    block_variable(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual void setPixmap(const QPixmap& pixmap) Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual void setPoint(const QPoint& point) Q_DECL_OVERRIDE;
    virtual QPoint getPoint() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QColor color_back = rgbColor(VARIABLE_COLOR);
    int font_size{12};
    QPoint startPos;
    QPainterPath block_path;
    QString block_text = "";
    QPixmap block_pixmap;
    QString code_text;
    QLineEdit* edit;
};


#endif // __BLOCK_VARIABLE__