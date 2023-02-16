

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
public:
    virtual void createPixmap() = 0;
};

/**
 * 在模板中获取类名
*/
namespace internal
{
    constexpr const static unsigned int FRONT_SIZE = sizeof("static const char* internal::GetTypeNameHelper<T>::GetTypeName() [with T = ") - 1u;
    constexpr const static unsigned int BACK_SIZE = sizeof("]") - 1u;
    
    template <typename T>
    struct GetTypeNameHelper
    {
        static const char* GetTypeName(void)
        {
            constexpr const static size_t size = sizeof(__PRETTY_FUNCTION__) - FRONT_SIZE - BACK_SIZE;
            static char typeName[size] = {};
            memcpy(typeName, __PRETTY_FUNCTION__ + FRONT_SIZE, size - 1u);
            return typeName;
        }
    };
}
 
template <typename T>
const char* GetTypeName(void)
{
    return internal::GetTypeNameHelper<T>::GetTypeName();
}

/**
 * 代码块的接口类，代码块类方法集合
 * 子类不必实现 Base 类中所有方法
*/
template<typename T>
class Base : public QLabel, block{
public:
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
        return GetTypeName<T>();
    }
};



#endif // __BLOCK_BASE__