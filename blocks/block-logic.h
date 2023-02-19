
#ifndef __BLOCK_LOGIC__
#define __BLOCK_LOGIC__


#include "block-base.h"
#include <QLineEdit>

class block_logic: public Base<block_logic> {
public:
    int row = 3;
    int widget_width{WIDGET_WIDTH + BLOCK_LEFT_WIDTH}, widget_height{WIDGET_HEIGHT * row};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    const QVector<BlockShape> withInsideBlocks{
        {BLOCK_LEFT_WIDTH, WIDGET_HEIGHT, {none, none, none, none}},
        {block_width, block_height, {none, female, male, none}},
        {block_width, block_height, {female, none, none, none}}
    };
    int color_back = LOGIC_COLOR;
    bool is_parent_block = true;
    QString block_text = "如果";
    QPixmap block_pixmap;
    QString code_text = "";
    block_logic(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE {};

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

};


#endif // __BLOCK_LOGIC__