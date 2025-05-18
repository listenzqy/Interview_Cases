#include "ThreeRuleClass.h"
#include <iostream>

ThreeRuleClass::ThreeRuleClass(const std::string& n) : name(n), resource(new int(0)) {
    std::cout << "ThreeRuleClass 构造函数被调用: " << name << std::endl;
}

ThreeRuleClass::~ThreeRuleClass() {
    std::cout << "ThreeRuleClass 析构函数被调用: " << name << std::endl;
    delete resource;
}

ThreeRuleClass::ThreeRuleClass(const ThreeRuleClass& other) : name(other.name), resource(new int(*other.resource)) {
    std::cout << "ThreeRuleClass 拷贝构造函数被调用: " << name << std::endl;
}

ThreeRuleClass& ThreeRuleClass::operator=(const ThreeRuleClass& other) {
    std::cout << "ThreeRuleClass 拷贝赋值运算符被调用: " << name << " = " << other.name << std::endl;
    if (this != &other) {
        delete resource;
        name = other.name;
        resource = new int(*other.resource);
    }
    return *this;
}

void ThreeRuleClass::setValue(int value) {
    *resource = value;
}

int ThreeRuleClass::getValue() const {
    return *resource;
}

void ThreeRuleClass::printInfo() const {
    std::cout << "ThreeRuleClass [" << name << "] 值: " << *resource << std::endl;
}