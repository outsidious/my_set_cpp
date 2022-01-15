#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <ctime>
#include <string>
#include <cstring>

const char mem_msg[] = "Memory error!\n";
const char range_msg[] = "Exit beyond of board!\n";

class SetException: public std::exception {
 public:
    SetException(const char* str);
    SetException(const char* str, const char* msg);
    SetException(const char* str, const std::string& mesg);
    SetException(const char* str, const char* msg, int data);
    SetException(const char* str, const char* msg, const char* time);

    virtual ~SetException() override;

    const char* what() const noexcept override
    {
        return msg;
    }

 private:
    char* msg;
};

class MemException: public SetException {
 public:
    MemException();
    MemException(const char* mesg);
    MemException(const std::string& mesg);
    MemException(const char* mesg, int data);
    MemException(const char* mesg, const char* time);
    ~MemException();
};

class RangeOutException: public SetException {
 public:
    RangeOutException();
    RangeOutException(const char* mesg);
    RangeOutException(const std::string& mesg);
    RangeOutException(const char* mesg, int data);
    RangeOutException(const char* mesg, const char* time);
    ~RangeOutException();
};

#endif // EXCEPTION_H
