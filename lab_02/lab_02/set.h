#ifndef SET_H
#define SET_H

#include <baseset.hpp>
#include <stddef.h>
#include <iostream>
#include "iterator.hpp"
#include "exception.hpp"
#include <memory>

using namespace std;

const int defaultMemSize = 4;

template<typename T>
class Set: public BaseSet
{
public:
    friend class Iterator<T>;
    friend class _Test_Set_Builder;
    Set();
    Set(size_t size, const T* array);
    Set(initializer_list<T>);
    Set(const Iterator<T> &begin, const Iterator<T> &end);
    explicit Set(const Set&);
    Set(Set&&) noexcept;
    ~Set();

    Iterator<T> begin();
    Iterator<T> end();

    const Set<T>& operator =(const Set<T>&);
    const Set<T>& operator =(Set<T>&&);
    const Set<T>& operator =(initializer_list<T>);

    bool Has(const T&) const;
    bool operator >(const T&) const;
    bool operator <(const T&) const;

    Iterator<T> begin() const;
    Iterator<T> end() const;

    bool Add(const T&);
    Set<T>& operator +=(const T&);
    Set<T>& operator |=(const T&);
    Set<T>& Union(const T&);
    Set<T> operator +(const T&) const;
    Set<T> operator |(const T&) const;
    Set<T>& Union(const Set<T>&);
    Set<T>& operator +=(const Set<T>&);
    Set<T>& operator |=(const Set<T>&);
    template<typename V>
    friend Set<V> operator +(const Set<V>&, const Set<V>&);
    template<typename V>
    friend Set<V> operator |(const Set<V>&, const Set<V>&);

    bool Delete(const T&);
    Set<T>& operator -=(const T&);
    Set<T>& operator /=(const T&);
    Set<T>& Difference(const T&);
    Set<T> operator -(const T&) const;
    Set<T> operator /(const T&) const;
    template<typename V>
    friend Set<V> Difference(const Set<V>&, const V&);
    Set<T>& Difference(const Set<T>&);
    Set<T>& operator -=(const Set<T>&);
    Set<T>& operator /=(const Set<T>&);
    template<typename V>
    friend Set<V> operator -(const Set<V>&, const Set<V>&);
    template<typename V>
    friend Set<V> operator /(const Set<V>&, const Set<V>&);

    Set<T>& Intersection(const Set<T>&);
    Set<T>& operator *=(const Set<T>&);
    Set<T>& operator &=(const Set<T>&);
    template<typename V>
    friend Set<V> operator *(const Set<V>&, const Set<V>&);
    template<typename V>
    friend Set<V> operator &(const Set<V>&, const Set<V>&);

    Set<T>& SymDifference(const Set<T>&);
    Set<T>& operator %=(const Set<T>&);
    Set<T>& operator ^=(const Set<T>&);
    template<typename V>
    friend Set<V> operator %(const Set<V>&, const Set<V>&);
    template<typename V>
    friend Set<V> operator ^(const Set<V>&, const Set<V>&);

    bool IsSubsetOf(const Set<T>&) const;
    bool Contain(const Set<T>&) const;
    template<typename V>
    friend bool operator >= (const Set<V>&, const Set<V>&);
    template<typename V>
    friend bool operator <= (const Set<V>&, const Set<V>&);
    template<typename V>
    friend bool operator >  (const Set<V>&, const Set<V>&);
    template<typename V>
    friend bool operator <  (const Set<V>&, const Set<V>&);
    template<typename V>
    friend bool operator == (const Set<V>&, const Set<V>&);
    template<typename V>
    friend bool operator != (const Set<V>&, const Set<V>&);

    template<typename V>
    friend std::ostream& operator <<(std::ostream& os, const Set<V>& set);

    void Clear();

protected:
    void alloc();

private:
    size_t memSize;
    shared_ptr<T[]> data;
};

#endif // SET_H
