//
// Created by a on 8/24/20.
//

#ifndef SMART_POINTER_SHARED_PTR_H
#define SMART_POINTER_SHARED_PTR_H

#include <cstddef>

template <typename T>
class SharedPtr{
public:
    SharedPtr(T *ptr);
    ~SharedPtr();

    SharedPtr(const SharedPtr& other);
    const SharedPtr& operator=(const SharedPtr& other);

    template <typename S>
    SharedPtr(const SharedPtr<S>& other);
    template <typename S>
    const SharedPtr& operator=(const SharedPtr<S>& other);

    T& operator*()const;
    T* operator->()const;
    operator bool()const;

    T* get()const;

private:
    T *m_ptr;
    size_t* m_refCounter;

    void deletePtr();

    template<typename U>
    friend class SharedPtr;

    friend class TestSmartPtr;
};



template <typename T>
inline SharedPtr<T>::SharedPtr(T *ptr):m_ptr(ptr), m_refCounter(NULL){
    m_refCounter = new size_t(1);
}


template <typename T>
inline SharedPtr<T>::~SharedPtr(){
    --*m_refCounter;

    if(!*m_refCounter){
        delete m_refCounter;
        m_refCounter = NULL;
        delete m_ptr;
        m_ptr = NULL;
    }
}


template <typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& other):m_ptr(other.m_ptr), m_refCounter(other.m_refCounter){
    ++*m_refCounter;
}


template <typename T>
inline const SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other){
    if(&other != this) {
        --*m_refCounter;

        if (!*m_refCounter) {
            delete m_refCounter;
            m_refCounter = NULL;
            delete m_ptr;
            m_ptr = NULL;
        }

        m_ptr = other.m_ptr;
        m_refCounter = other.m_refCounter;
        ++*m_refCounter;
    }

    return *this;
}


template <typename T>
template <typename S>
inline SharedPtr<T>::SharedPtr(const SharedPtr<S>& other):m_ptr(other.m_ptr), m_refCounter(other.m_refCounter){
    ++*m_refCounter;
}


template <typename T>
template <typename S>
inline const SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<S>& other){
    if(&other != this) {
        --*m_refCounter;

        if (!*m_refCounter) {
            delete m_refCounter;
            m_refCounter = NULL;
            delete m_ptr;
            m_ptr = NULL;
        }

        m_ptr = other.m_ptr;
        m_refCounter = other.m_refCounter;
        ++*m_refCounter;
    }

    return *this;
}


template <typename T>
inline T& SharedPtr<T>::operator*()const{
    return *m_ptr;
}


template <typename T>
inline T* SharedPtr<T>::operator->()const{
    return m_ptr;
}


template <typename T>
inline SharedPtr<T>::operator bool()const{
    return m_ptr != NULL;
}


template <typename T>
inline T* SharedPtr<T>::get()const{
    return m_ptr;
}


template <typename T>
void SharedPtr<T>::deletePtr(){
    --*m_refCounter;

    if (!*m_refCounter) {
        delete m_refCounter;
        m_refCounter = NULL;
        delete m_ptr;
        m_ptr = NULL;
    }
}


#endif //SMART_POINTER_SHARED_PTR_H
