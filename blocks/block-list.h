
#ifndef __BLOCK_LIST__
#define __BLOCK_LIST__

#include "block-base.h"
#include <QLineEdit>

class block_list: public block_base {
public:
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockShape block_shape{block_width, block_height, {male, none, female, male}};
    int color_back = ARRAY_COLOR;
    bool is_parent_block = false;
    QString block_text = "创建空数组";
    QPixmap block_pixmap;
    QString code_text = "list()";
    BlockType block_type = BlockType::normal;
    block_list(QWidget *parent);
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
};


#endif // __BLOCK_LIST__