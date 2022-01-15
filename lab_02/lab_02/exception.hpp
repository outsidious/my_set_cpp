#ifndef EXCEPTIONIMP_H
#define EXCEPTIONIMP_H

#include "exception.h"
#include <string.h>

SetException::SetException(const char* str)
{
    size_t len = strlen(str);
    msg = new char[len+1];
    memcpy(msg, str, len+1);
}

SetException::SetException(const char* str, const char* mesg)
{
    size_t len1 = strlen(str);
    size_t len = strlen(str) + strlen(mesg) + 1;

    msg = new char[len];
    if (!msg)
    {
        return;
    }

    memcpy(msg, str, len1 + 1);
    strcat_s(msg, len, mesg);
}

SetException::SetException(const char *str, const std::string& mesg)
{
    size_t len = strlen(str) + mesg.size() + 1;

    msg = new char[len];
    if (!msg)
    {
        return;
    }

    strcat_s(msg, len, mesg.c_str());
}

SetException::SetException(const char* str, const char* mesg, const char* time)
{
    size_t len1 = strlen(str);
    size_t len = strlen(str) + strlen(mesg) + strlen(time) + 1;

    msg = new char[len];

    if (!msg)
    {
        return;
    }

    memcpy(msg, str, len1 + 1);
    strcat_s(msg, len, mesg);
    strcat_s(msg, len, time);
}

SetException::SetException(const char* str, const char* mesg, int data)
{
    size_t len1 = strlen(str);
    size_t len = strlen(str) + strlen(mesg) + 11;

    msg = new char[len];
    if (!msg)
    {
        return;
    }

    memcpy(msg, str, len1 + 1);
    char data_s[10];

    _itoa_s(data, data_s, 10);
    strcat_s(msg, len, mesg);
    strcat_s(msg, len, data_s);
}

MemException::MemException():
    SetException(mem_msg) {}

MemException::MemException(const char* mesg):
    SetException(mem_msg, mesg) {}

MemException::MemException(const std::string& mesg):
    SetException(mem_msg, mesg) {}

MemException::MemException(const char* mesg, int data):
    SetException(mem_msg, mesg, data) {}

MemException::MemException(const char* mesg, const char* time):
    SetException(range_msg, mesg, time) {}

RangeOutException::RangeOutException():
    SetException(range_msg) {}

RangeOutException::RangeOutException(const char* mesg):
    SetException(range_msg, mesg) {}

RangeOutException::RangeOutException(const std::string& mesg):
    SetException(range_msg, mesg) {}

RangeOutException::RangeOutException(const char* mesg, int data):
    SetException(range_msg, mesg, data) {}

RangeOutException::RangeOutException(const char* mesg, const char* time):
    SetException(range_msg, mesg, time) {}

SetException::~SetException() {}
MemException::~MemException() {}
RangeOutException::~RangeOutException() {}

#endif // EXCEPTIONIMP_H
