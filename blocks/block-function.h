
#ifndef __BLOCK_FUNCTION__
#define __BLOCK_FUNCTION__


#include "block-base.h"
#include <QLineEdit>

class block_function: public block_base {
public:
    int row = 3;
    int widget_width{WIDGET_WIDTH + BLOCK_LEFT_WIDTH}, widget_height{WIDGET_HEIGHT * row};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    const QVector<BlockShape> withInsideBlocks{
        {BLOCK_LEFT_WIDTH, block_height, {none, none, none, none}},
        {block_width, block_height, {none, none, male, none}},
        {block_width, block_height, {female, none, none, none}}
    };
    int color_back = FUNCTION_COLOR;
    bool is_parent_block = true;
    QString block_text = "函数";
    QPixmap block_pixmap;
    QString code_text = "";
    bool read_only;
    block_function(QWidget *parent, bool read_only);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QLineEdit* edit;
};


#endif // __BLOCK_FUNCTION__