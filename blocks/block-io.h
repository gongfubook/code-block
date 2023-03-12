
#ifndef __BLOCK_IO__
#define __BLOCK_IO__


#include "block-base.h"
#include <QLineEdit>

class block_print: public block_base {
public:
    int row = 1;
    int widget_width{WIDGET_IO_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockShape block_shape{block_width, block_height, {male, female, female, none}};
    int color_back = FUNCTION_COLOR;
    bool is_parent_block = true;
    QString block_text = "输出";
    QPixmap block_pixmap;
    QString code_text_begin = "print(";
    QString code_text_end = ")";
    QString code_text = "print()";
    BlockType block_type = BlockType::pluggable;
    block_print(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;
    virtual BlockType getBlockType() Q_DECL_OVERRIDE;
    virtual BlockShape getBlockShape() Q_DECL_OVERRIDE;
    virtual int getBlockRow() Q_DECL_OVERRIDE;
    virtual QVector<BlockShape> getBlockShapes() Q_DECL_OVERRIDE;
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#endif // __BLOCK_IO__