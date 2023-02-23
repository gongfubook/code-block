
#ifndef __BLOCK_STRING__
#define __BLOCK_STRING__


#include "block-base.h"
#include <QLineEdit>

class block_string: public block_base {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockShape block_shape{block_width, block_height, {male, none, female, male}};
    bool read_only;
    int color_back = STRING_COLOR;
    bool is_parent_block = false;
    QPixmap block_pixmap;
    QString code_text = "";
    BlockType block_type = BlockType::normal;
    block_string(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;
    virtual BlockType getBlockType() Q_DECL_OVERRIDE;
    virtual BlockShape getBlockShape() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QLineEdit* edit;
};


#endif // __BLOCK_STRING__