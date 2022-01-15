#ifndef BASESET_H
#define BASESET_H
#include <stddef.h>

class BaseSet
{
public:
    BaseSet();
    BaseSet(const BaseSet&);
    virtual ~BaseSet() =  0;
    virtual size_t GetCountElement() const;
    bool IsEmpty() const;

protected:
    size_t countElement;
};

#endif // BASESET_H
