#ifndef SETIMP_H
#define SETIMP_H

#include <set.h>

template<typename T>
Set<T>::Set()
{
    countElement = 0;
    memSize = defaultMemSize;
    alloc();
}

template<class T>
void Set<T>::alloc()
{
    memSize *= 2;
    try{
        shared_ptr<T[]> tmp (new T[memSize], default_delete<T[]>());
        Iterator<T> iterator(*this);
        for (size_t i = 0; i < countElement; i++)
        {
            *(tmp.get() + i) = *iterator;
            iterator++;
        }
        data.reset();
        data = tmp;
    }
    catch (bad_alloc)
    {
       throw MemException();
    }
}

template<typename T>
Set<T>::Set(const Set& other):
    BaseSet ()
{
    memSize = other.memSize;
    for (Iterator<T> iterator(other); iterator; ++iterator)
    {
        Add(*iterator);
    }
    countElement = other.countElement;
}

template <typename T>
Set<T>::Set(initializer_list<T> init_list)
{
    if (0 == init_list.size())
    {
        Set();
    }
    else
    {
        memSize = init_list.size();
        alloc();
        for (auto& value : init_list)
        {
            Add(value);
        }
        countElement = init_list.size();
    }
}

template<typename T>
Set<T>::Set(Set&& other) noexcept:
    memSize(other.memSize),
    data(other.data)
{
    countElement = other.countElement;
    other.countElement = 0;
    other.memSize = 0;
    other.data = nullptr;
}

template<typename T>
Set<T>::Set(size_t size, const T* array)
{
    memSize = size;
    alloc();
    for (size_t i = 0; i < size; ++i)
    {
        Add(array[i]);
    }
}

template<typename T>
Set<T>::Set(const Iterator<T> &begin, const Iterator<T> &end)
{
    size_t qua = end - begin;
    countElement = 0;
    memSize = qua;
    alloc();
    Iterator<T> it = begin;
    for (size_t i = 0; i < qua; ++i)
    {
        Add(*it);
        ++it;
    }
}

template<typename T>
Iterator<T> Set<T>::begin()
{
    Iterator<T> it(*this);
    return it;
}

template<typename T>
Iterator<T> Set<T>::end()
{
    Iterator<T> it(*this);
    it += countElement;
    return it;
}

template<typename T>
Set<T>::~Set()
{
    data.reset();
}


template <typename T>
const Set<T>& Set<T>::operator =(const Set<T>& set)
{
    countElement = 0;
    Iterator<T> iterator(set);
    for (; iterator; ++iterator)
    {
        Add(*iterator);
    }
    countElement = set.countElement;
    return *this;
}

template<typename T>
const Set<T>& Set<T>::operator =(initializer_list<T> list)
{
    for (auto& value : list)
    {
        Add(value);
    }
    countElement = list.size();
    return *this;
}

template <typename T>
const Set<T>& Set<T>::operator =(Set<T>&& other)
{
    memSize = other.memSize;
    data = other.data;
    countElement = other.countElement;

    other.countElement = 0;
    other.memSize = 0;
    other.data = nullptr;
    return *this;
}


template<typename T>
bool Set<T>::Has(const T& element) const
{
    if (IsEmpty())
        return false;
    Iterator<T> iterator(*this);
    for (size_t i = 0; i < countElement; i++)
    {
        if (*iterator == element)
        {
            return true;
        }
        iterator++;
    }
    return false;
}

template<typename T>
bool Set<T>::operator >(const T& element) const
{
    return Has(element);
}

template<typename T>
bool Set<T>::operator <(const T& element) const
{
    return !Has(element);
}


//
//
//ADD SECTION
//
template<typename T>
bool Set<T>::Add(const T& element)
{
    if (Has(element))
        return false;
    if (countElement == memSize || countElement == 0)
        alloc();
    *(data.get() + countElement) = element;
    countElement += 1;
    return true;
}

template<typename T>
Set<T>& Set<T>::Union(const Set<T>& other)
{
    Set<T> set;
    Iterator<T> iThis(*this);
    Iterator<T> iOther(other);
    for (; iThis&&iOther; iThis++, iOther++)
    {
        set.Add(*iThis);
        set.Add(*iOther);
    }
    *this = set;
    return *this;
}

template<typename T>
Set<T>& Set<T>::Union(const T& element)
{
    Set<T> set(*this);
    set.Add(element);
    *this = set;
    return *this;
}

template <typename T>
Set<T>& Set<T>::operator +=(const Set<T>& other){
    Union(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>:: operator +=(const T& element)
{
    Add(element);
    return *this;
}

template <typename T>
Set<T> Set<T>:: operator +(const T& element) const
{
    Set<T> set;
    set = *this;
    set += element;
    return set;
}

template <typename T>
Set<T> Set<T>:: operator |(const T& element) const
{
    Set<T> set;
    set = *this;
    set += element;
    return set;
}

template <typename T>
Set<T>& Set<T>::operator |=(const Set<T>& other)
{
    Union(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>:: operator |=(const T& element)
{
    Add(element);
    return *this;
}

template<typename T>
Set<T> operator +(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Union(right);
    return set;
}

template<typename T>
Set<T> operator |(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Union(right);
    return set;
}


//
//
// DELETE SECTION
template<typename T>
bool Set<T>::Delete(const T& element)
{
    if (!Has(element))
        return false;
    for (size_t i = 0; i < countElement; ++i)
    {
        if (*(data.get() + i) == element)
        {
            for (size_t j = i; j < countElement; ++j)
            {
                *(data.get() + j) = *(data.get() + j + 1);
            }
            --countElement;
            return true;
        }
    }
    return false;
}

template<typename T>
Set<T>& Set<T>::Difference(const Set<T>& other)
{
    for (Iterator<T> iterator = other; iterator; ++iterator)
    {
        Delete(*iterator);
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::Difference(const T& element)
{
    Delete(element);
    return *this;
}

template <typename T>
Set<T>& Set<T>::operator -=(const Set<T>& other)
{
    Difference(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>:: operator -=(const T& element)
{
    Delete(element);
    return *this;
}

template <typename T>
Set<T> Set<T>:: operator -(const T& element) const
{
    Set<T> set;
    set = *this;
    set -= element;
    return set;
}

template <typename T>
Set<T>& Set<T>::operator /=(const Set<T>& other){
    Difference(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>:: operator /=(const T& element)
{
    Delete(element);
    return *this;
}

template <typename T>
Set<T> Set<T>:: operator /(const T& element) const
{
    Set<T> set;
    set = *this;
    set -= element;
    return set;
}


template<typename T>
void Set<T>::Clear()
{
    if (IsEmpty())
        return;
    countElement = 0;
}

template<typename T>
Set<T> operator -(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Difference(right);
    return set;
}

template<typename T>
Set<T> operator /(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Difference(right);
    return set;
}
//END
//


template<typename T>
Set<T>& Set<T>::Intersection(const Set<T>& other)
{
    Set<T> set;
    Iterator<T> iThis(*this);
    for (; iThis; iThis++)
    {
        Iterator<T> iOther(other);
        for (; iOther; iOther++)
        {
            if (*iThis == *iOther)
            {
                set.Add(*iThis);
            }
        }
    }
    *this = set;
    return *this;
}

template<typename T>
Set<T>& Set<T>::SymDifference(const Set<T>& other)
{
    Union(other);
    for (Iterator<T> iThis(*this); iThis; iThis++)
    {
        for (Iterator<T> iOther(other); iOther; iOther++)
        {
            if (*iThis == *iOther)
            {
                Delete(*iThis);
            }
        }
    }

    return *this;
}


template <typename T>
Set<T>& Set<T>::operator *=(const Set<T>& other)
{
    Intersection(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>::operator &=(const Set<T>& other)
{
    Intersection(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>::operator %=(const Set<T>& other)
{
    SymDifference(other);
    return  *this;
}

template <typename T>
Set<T>& Set<T>::operator ^=(const Set<T>& other)
{
    SymDifference(other);
    return  *this;
}

template<typename T>
Set<T> operator *(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Intersection(right);
    return set;
}

template<typename T>
Set<T> operator &(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.Intersection(right);
    return set;
}

template<typename T>
Set<T> operator %(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.SymDifference(right);
    return set;
}

template<typename T>
Set<T> operator ^(const Set<T>& left, const Set<T>& right)
{
    Set<T> set = left;
    set.SymDifference(right);
    return set;
}

template <typename T>
bool Set<T>::IsSubsetOf(const Set<T>& set) const
{
    if (IsEmpty())
    {
        return true;
    }

    bool result = true;
    for (Iterator<T> iterator(*this); result && iterator; ++iterator)
    {
        if (!set.Has(*iterator))
        {
            result = false;
        }
    }

    return result;
}

template <typename T>
bool Set<T>::Contain(const Set<T>& set) const
{
    if (IsEmpty())
    {
        return false;
    }
    return set.IsSubsetOf(*this);
}


template<typename T>
bool operator >=(const Set<T>& left, const Set<T>& right)
{
    return right.IsSubsetOf(left);
}

template<typename T>
bool operator <=(const Set<T>& left, const Set<T>& right)
{
    return left.IsSubsetOf(right);
}

template<typename T>
bool operator ==(const Set<T>& left, const Set<T>& right)
{
    return right.IsSubsetOf(left) && left.IsSubsetOf(right);
}

template<typename T>
bool operator !=(const Set<T>& left, const Set<T>& right)
{
    return !(right.IsSubsetOf(left) && left.IsSubsetOf(right));
}

template<typename T>
bool operator >(const Set<T>& left, const Set<T>& right)
{
    return right.IsSubsetOf(left) && !left.IsSubsetOf(right);
}

template<typename T>
bool operator <(const Set<T>& left, const Set<T>& right)
{
    return !right.IsSubsetOf(left) && left.IsSubsetOf(right);
}


template<typename T>
std::ostream& operator <<(std::ostream& os, const Set<T>& set)
{
    Iterator<T> iterator(set);

    if (!iterator)
    {
        os << "Set is empty!\n";
        return os;
    }

    os << "{ " << *iterator;
    for (iterator++; iterator; iterator++)
    {
        os << ", " << *iterator;
    }

    os << " }\n";

    return os;
}

class _Test_Set_Builder
{
public:
    _Test_Set_Builder(initializer_list<int> arr) {
        memSize = arr.size() * 16;
        shared_ptr<int[]> tmp (new int[arr.size() * 2], default_delete<int[]>());
        int i = 0;
        for (auto val: arr) {
            *(tmp.get() + i) = val;
            ++i;
        }
        countElement = arr.size();
        ptr = tmp;
    }

    ~_Test_Set_Builder()
    {
        ptr.reset();
    }

    Set<int> getSet() {
        Set<int> set = Set<int>();
        set.data = ptr;
        set.memSize = memSize;
        set.countElement = countElement;
        return set;
    }
private:
    shared_ptr<int[]> ptr;
    size_t memSize = 0;
    size_t countElement = 0;
};

#endif // SETIMP_H
