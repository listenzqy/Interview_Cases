#ifndef DEEP_STRING_H
#define DEEP_STRING_H

#include <iostream> // For std::cout, std::endl
#include <cstring>  // For strlen, strcpy

class DeepString {
public:
    char* data;
    int len;

    DeepString(const char* s = "");
    ~DeepString();

    // 深拷贝构造函数
    DeepString(const DeepString& other);

    // 深拷贝赋值运算符
    DeepString& operator=(const DeepString& other);

    void print(const char* name) const;
    void modify(const char* new_str);
};

// 测试函数声明
void testDeepCopy();

#endif //DEEP_STRING_H