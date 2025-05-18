#ifndef SHALLOW_STRING_H
#define SHALLOW_STRING_H

#include <iostream> // For std::cout, std::endl (used in some inline or templated methods if any, or for convenience)
#include <cstring>  // For strlen, strcpy

class ShallowString {
public:
    char* data;
    int len;

    ShallowString(const char* s = "");
    ~ShallowString();

    // 默认的拷贝构造函数（或显式定义的浅拷贝构造函数）
    ShallowString(const ShallowString& other);

    // 默认的拷贝赋值运算符（或显式定义的浅拷贝赋值运算符）
    ShallowString& operator=(const ShallowString& other);

    void print(const char* name) const;
    void modify(const char* new_str);
};

// 测试函数声明
void testShallowCopy();

#endif //SHALLOW_STRING_H