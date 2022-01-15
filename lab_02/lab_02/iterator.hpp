#ifndef ITERATORIMP_H
#define ITERATORIMP_H

#include <iterator.h>

template<typename T>
Iterator<T>::Iterator()
{
    size = 0;
    index = 0;
}

template<typename T>
Iterator<T>::Iterator(const Set<T>& set)
{
    size = set.countElement;
    index = 0;
    ptr = set.data;
}

template<typename T>
Iterator<T>::~Iterator()
{
    ptr.reset();
}

template <typename T>
T* Iterator<T>::getCurPtr() const
{
    if (!ptr.expired() && 0 <= index && index <= size)
    {
        shared_ptr<T[]> shar = ptr.lock();
        return (shar.get() + index);
    }
    else
    {
        throw RangeOutException();
    }
}

template <typename T>
const T& Iterator<T>::operator *() const
{
    return  *getCurPtr();
}

template <typename T>
const T* Iterator<T>::operator ->() const
{
    return getCurPtr();
}

template <typename T>
Iterator<T>& Iterator<T>::operator =(const Iterator<T>& other)
{
    size = other.size;
    index = other.index;
    ptr = other.ptr;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator =(const Set<T>& other)
{
    size = other.countElement;
    index = 0;
    ptr = other.data;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator +(int number) const{
    Iterator<T> tmp = *this;
    tmp.index += number;
    return tmp;
}

template <typename T>
Iterator<T> Iterator<T>::operator -(int number) const{
    Iterator<T> tmp = *this;
    tmp.index -= number;
    return tmp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator ++(){
    index += 1;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator --(){
    index -= 1;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator ++(int)
{
    Iterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
Iterator<T> Iterator<T>::operator --(int)
{
    Iterator<T> tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator +=(int number){
    for (int i = 0; i < number; i++)
    {
        ++(*this);
    }
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator -=(int number)
{
    for (int i = 0; i < number; i++)
    {
        --(*this);
    }
    return *this;
}

template<typename T>
Iterator<T>::operator bool() const {
    bool res = true;
    if (index >= size || 0 == size)
    {
        res = false;
    }
    return res;
}


class _Test_Iterator_Builder
{
public:
    _Test_Iterator_Builder() {
        shared_ptr<int[]> tmp (new int[32], default_delete<int[]>());
        *(tmp.get()) = 1;
        *(tmp.get() + 1) = 2;
        *(tmp.get() + 2) = 3;
        ptr = tmp;
    }

    ~_Test_Iterator_Builder()
    {
        ptr.reset();
    }


    Iterator<int> getBegin()  {
       Iterator<int> res = Iterator<int>();
       res.ptr = ptr;
       res.index = 0;
       res.size = 3;
       return res;
    }

    Iterator<int> getEnd() {
        Iterator<int> res = Iterator<int>();
        res.ptr = ptr;
        res.index = 3;
        res.size = 3;
        return res;
    }
private:
    shared_ptr<int[]> ptr;
};

class _Test_Iterator
{
public:
    _Test_Iterator(Iterator<int> in) {
        it = in;
    }

    size_t getSize() {
        return it.size;
    }

    size_t getIndex() {
        return it.index;
    }

    weak_ptr<int[]> getPtr() {
        return it.ptr;
    }

private:
    Iterator<int> it;
};
#endif // ITERATORIMP_H
