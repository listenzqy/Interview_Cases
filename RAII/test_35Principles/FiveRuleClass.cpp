#include "FiveRuleClass.h"
#include <iostream>

FiveRuleClass::FiveRuleClass(const std::string& n) : name(n), resource(new int(0)) {
    std::cout << "FiveRuleClass 构造函数被调用: " << name << std::endl;
}

FiveRuleClass::~FiveRuleClass() {
    std::cout << "FiveRuleClass 析构函数被调用: " << name << std::endl;
    delete resource;
}

FiveRuleClass::FiveRuleClass(const FiveRuleClass& other) : name(other.name), resource(new int(*other.resource)) {
    std::cout << "FiveRuleClass 拷贝构造函数被调用: " << name << std::endl;
}

FiveRuleClass& FiveRuleClass::operator=(const FiveRuleClass& other) {
    std::cout << "FiveRuleClass 拷贝赋值运算符被调用: " << name << " = " << other.name << std::endl;
    if (this != &other) {
        delete resource;
        name = other.name;
        resource = new int(*other.resource);
    }
    return *this;
}

FiveRuleClass::FiveRuleClass(FiveRuleClass&& other) noexcept : name(std::move(other.name)), resource(other.resource) {
    std::cout << "FiveRuleClass 移动构造函数被调用" << std::endl;
    other.resource = nullptr; // 防止原对象析构时释放资源
}

FiveRuleClass& FiveRuleClass::operator=(FiveRuleClass&& other) noexcept {
    std::cout << "FiveRuleClass 移动赋值运算符被调用" << std::endl;
    if (this != &other) {
        delete resource;
        name = std::move(other.name);
        resource = other.resource;
        other.resource = nullptr; // 防止原对象析构时释放资源
    }
    return *this;
}

void FiveRuleClass::setValue(int value) {
    *resource = value;
}

int FiveRuleClass::getValue() const {
    return *resource;
}

void FiveRuleClass::printInfo() const {
    std::cout << "FiveRuleClass [" << name << "] 值: " << (resource ? *resource : -1) << std::endl;
}