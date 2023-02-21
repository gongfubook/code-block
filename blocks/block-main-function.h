

#ifndef __BLOCK_MAIN_FUNCTION__
#define __BLOCK_MAIN_FUNCTION__


#include "block-function.h"
#include <QLineEdit>

class block_main_function: public block_base {
public:
    int row = 3;
    int widget_width{WIDGET_WIDTH + BLOCK_LEFT_WIDTH}, widget_height{WIDGET_HEIGHT * row};
    int block_width{BLOCK_WIDTH}, block_height{BLOCK_HEIGHT};
    const QVector<BlockShape> withInsideBlocks{
        {BLOCK_LEFT_WIDTH, block_height, {none, none, none, none}},
        {block_width, block_height, {none, female, male, none}},
        {block_width, block_height, {female, none, none, none}}
    };
    int color_back = FUNCTION_COLOR;
    bool is_parent_block = true;
    QString block_text = "主函数";
    QPixmap block_pixmap;
    QString code_text_begin = "int main(int argc, char* argv[]) {\n";
    QString code_text_end = "\treturn 0;\n}\n";
    QString code_text = "";
    block_main_function(QWidget *parent);
    ~block_main_function();
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#endif // __BLOCK_MAIN_FUNCTION__