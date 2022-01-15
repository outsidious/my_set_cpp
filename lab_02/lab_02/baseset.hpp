#ifndef BASESETIMP_H
#define BASESETIMP_H

#include <baseset.h>

BaseSet::BaseSet():
    countElement(0){}

BaseSet::BaseSet(const BaseSet& other):
   countElement(other.countElement){}

BaseSet::~BaseSet() {}

size_t BaseSet::GetCountElement() const
{
    return countElement;
}

bool BaseSet::IsEmpty() const
{
    return 0 == countElement;
}

#endif // BASESETIMP_H
