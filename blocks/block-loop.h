
#ifndef __BLOCK_LOOP__
#define __BLOCK_LOOP__


#include "block-base.h"
#include <QLineEdit>
#include <QDebug>

class block_loop: public block_base {
public:
    int row = 3;
    int widget_width{WIDGET_WIDTH + BLOCK_LEFT_WIDTH}, widget_height{WIDGET_HEIGHT * row};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    const QVector<BlockShape> withInsideBlocks{
        {block_width, block_height, {none, female, female, none}},
        {block_width, block_height, {male, none, none, none}}
    };
    int color_back = LOOP_COLOR;
    bool is_parent_block = true;
    QString block_text = "循环次数";
    QPixmap block_pixmap;
    QString code_text = "";
    BlockType block_type = BlockType::with_inside;
    block_loop(QWidget *parent);
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


#endif // __BLOCK_LOOP__