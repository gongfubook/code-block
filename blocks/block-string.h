
#ifndef __BLOCK_STRING__
#define __BLOCK_STRING__


#include "block-base.h"
#include <QLineEdit>

class block_string: public Base<block_string> {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockConnector connector{male, none, none, none};
    bool read_only;
    int color_back = STRING_COLOR;
    bool is_parent_block = false;
    QPixmap block_pixmap;
    QString code_text = "";
    block_string(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    QString get_edit_text();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QLineEdit* edit;
};


#endif // __BLOCK_STRING__