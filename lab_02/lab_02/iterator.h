#ifndef ITERATOR_H
#define ITERATOR_H

#include <exception.hpp>
#include <stddef.h>
#include <memory>
#include <iostream>

using namespace std;

template <typename T>
class Set;

template<typename T>
class Iterator: public std::iterator<std::output_iterator_tag, T> {
public:
    Iterator(const Iterator<T>& it) = default;
    Iterator();
    Iterator(const Set<T>&);
    ~Iterator();

    const T& operator *() const;
    const T* operator ->() const;

    Iterator<T>& operator =(const Iterator<T>&);
    Iterator<T>& operator =(const Set<T>&);

    Iterator<T> operator +(int) const;
    Iterator<T> operator -(int) const;

    Iterator<T>& operator ++();
    Iterator<T>& operator --();
    Iterator<T> operator ++(int);
    Iterator<T> operator --(int);

    Iterator<T>& operator +=(int);
    Iterator<T>& operator -=(int);

    operator bool() const;
    friend class _Test_Iterator_Builder;
    friend class _Test_Iterator;

protected:
    weak_ptr<T[]> ptr;

private:
    T* getCurPtr() const;
    size_t index = 0;
    size_t size;
};

#endif // ITERATOR_H
