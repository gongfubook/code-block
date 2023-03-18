#ifndef __BLOCK_LOOP_OPENAI_H__
#define __BLOCK_LOOP_OPENAI_H__
#include <QLineEdit>
#include "block-base.h"
#include <QWidget>

class block_loop_openai : public block_base {
public:
    int row = 3;
    int widget_width{ WIDGET_IO_WIDTH }, widget_height{ WIDGET_HEIGHT };
    int block_width{ BLOCK_IO_WIDTH }, block_height{ BLOCK_HEIGHT };
    BlockShape block_shape{ block_width, block_height, { male, none, female, none } };
    const QVector<BlockShape> withInsideBlocks{
        {block_width, block_height, {none, female, female, none}},
        {block_width, block_height, {male, none, none, none}}
    };
    int color_back = LOOP_COLOR;
    bool is_parent_block = true;
    QPixmap block_pixmap;
    QString block_text = "for i in range";
    QString code_text = "";
    BlockType block_type = BlockType::pluggable;
    block_loop_openai(QWidget *parent = nullptr);
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
private:
    QLineEdit* edit;
};

#endif // __BLOCK_LOOP_OPENAI_H__
