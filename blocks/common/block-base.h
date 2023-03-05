

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
#include <memory>
#include <string>

#include <QWidget>
#include <Qcolor>

#include <QMouseEvent>
#include <QPixmap>
#include <QLabel>

#include "block-color.h"
#include "block-size.h"
#include "block-types.h"

/**
 * 代码块的接口类
 * 接口类的方法子类必须实现
*/

class block{
    virtual void createPixmap() = 0;
    virtual QPixmap getPixmap() = 0;
    virtual bool isParentBlock() = 0;
    virtual void insertCode(const QString &code) = 0;
    virtual QString toCode() = 0;
    virtual QString whatsThisBlockName() = 0;
    virtual BlockType getBlockType() = 0;
    virtual BlockShape getBlockShape() = 0;
};


class block_base : public QLabel, block{
public:
    int widget_width{WIDGET_WIDTH}, widget_height{WIDGET_HEIGHT};
    int block_width{BLOCK_IO_WIDTH}, block_height{BLOCK_HEIGHT};
    BlockShape block_shape{block_width, block_height, {male, none, female, none}};
    bool read_only;
    int color_back = VARIABLE_COLOR;
    bool is_parent_block = true;
    QPixmap block_pixmap;
    QString code_text = "";
    BlockType block_type = BlockType::normal;
    block_base(QWidget *parent);
    virtual void createPixmap() Q_DECL_OVERRIDE;
    virtual QPixmap getPixmap() Q_DECL_OVERRIDE;
    virtual bool isParentBlock() Q_DECL_OVERRIDE;
    virtual void insertCode(const QString &code) Q_DECL_OVERRIDE;
    virtual QString toCode() Q_DECL_OVERRIDE;
    virtual QString whatsThisBlockName() Q_DECL_OVERRIDE;
    virtual BlockType getBlockType() Q_DECL_OVERRIDE;
    virtual BlockShape getBlockShape() Q_DECL_OVERRIDE;
    // virtual friend QDataStream &operator<<(QDataStream &output, block_base * self){
    //     output << self->whatsThisBlockName();
    // }
    // virtual friend QDataStream &operator>>(QDataStream & , block_base * self);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};


#define HoverEvent                             \
    bool event(QEvent * e){                    \
        switch(e->type()){                                 \
            case QEvent::HoverEnter:                       \
                hoverEnter(static_cast<QHoverEvent*>(e));  \
                return true;\
                break;\
            case QEvent::HoverLeave:\
                hoverLeave(static_cast<QHoverEvent*>(e));\
                return true;\
                break;\
            case QEvent::HoverMove:\
                hoverMove(static_cast<QHoverEvent*>(e));\
                return true;\
                break;\
            default:\
                break;\
        }\
        return QWidget::event(e);\
    }\
    void hoverEnter(QHoverEvent * event){\
        qDebug() << Q_FUNC_INFO << event->type();\
    }\
    void hoverLeave(QHoverEvent * event){\
        qDebug() << Q_FUNC_INFO << event->type();\
    }\
    void hoverMove(QHoverEvent * event){\
        qDebug() << Q_FUNC_INFO << event->type();\
    } \


#endif // __BLOCK_BASE__