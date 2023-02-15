

#ifndef __BLOCK_BASE__
#define __BLOCK_BASE__

#include <stdint.h>
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
*/
class block{
    virtual void createPixmap() = 0;
};

/**
 * 代码块常用方法类
*/
template<typename T>
class Base : public QLabel, block{
    Base(QWidget * parent): QLabel(parent){}
    virtual void createPixmap(){}
    void block_base::setPixmap(const QPixmap& pixmap){
        T* self = static_cast<T*>(this);
        self->block_pixmap = pixmap;
    }

    QPixmap block_base::getPixmap(){
        T* self = static_cast<T*>(this);
        return self->block_pixmap;
    }

    void block_base::setPoint(const QPoint& point){
        T* self = static_cast<T*>(this);
        self->move(point);
    }

    QPoint block_base::getPoint(){
        T* self = static_cast<T*>(this);
        return self->pos();
    }

    bool block_base::isParentBlock(){
        T* self = static_cast<T*>(this);
        return false;
    }

    void block_base::insertCode(const QString &code){
        T* self = static_cast<T*>(this);
        return;
    }

    QString block_base::toCode(){
        T* self = static_cast<T*>(this);
        return self->code_text;
    }

    QString block_base::whatsThisBlockName(){
        T* self = static_cast<T*>(this);
        return "base";
    }
};



#endif // __BLOCK_BASE__