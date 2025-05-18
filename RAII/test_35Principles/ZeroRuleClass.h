#ifndef ZERO_RULE_CLASS_H
#define ZERO_RULE_CLASS_H

#include <string>
#include <vector>

// 零法则示例：不需要自定义任何特殊成员函数
class ZeroRuleClass {
private:
    std::string name;
    std::vector<int> data;

public:
    ZeroRuleClass(const std::string& n);
    
    void addData(int value);
    void printInfo() const;
    
    // 不需要自定义析构函数、拷贝构造函数、拷贝赋值运算符
    // 编译器生成的默认版本已经足够
};

#endif // ZERO_RULE_CLASS_H