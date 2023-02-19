
#ifndef __BLOCK_NUMBER__
#define __BLOCK_NUMBER__


#include "block-base.h"
#include <QLineEdit>

class block_number: public Base<block_number> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockShape block_shape{block_width, block_height, {male, none, none, none}};
    bool read_only;
    int color_back = MATH_COLOR;
    bool is_parent_block = false;
    QPixmap block_pixmap;
    QString code_text = "";
    block_number(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE {};
    QString get_edit_text();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QLineEdit* edit;
};


#endif // __BLOCK_NUMBER__