#include "ZeroRuleClass.h"
#include <iostream>

ZeroRuleClass::ZeroRuleClass(const std::string& n) : name(n) {
    std::cout << "ZeroRuleClass 构造函数被调用: " << name << std::endl;
}

void ZeroRuleClass::addData(int value) {
    data.push_back(value);
}

void ZeroRuleClass::printInfo() const {
    std::cout << "ZeroRuleClass [" << name << "] 包含 " << data.size() << " 个元素" << std::endl;
}