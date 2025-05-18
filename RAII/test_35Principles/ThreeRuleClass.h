#ifndef THREE_RULE_CLASS_H
#define THREE_RULE_CLASS_H

#include <string>

// 三法则示例：管理原始资源
class ThreeRuleClass {
private:
    std::string name;
    int* resource;

public:
    // 构造函数
    ThreeRuleClass(const std::string& n);
    
    // 1. 析构函数
    ~ThreeRuleClass();
    
    // 2. 拷贝构造函数
    ThreeRuleClass(const ThreeRuleClass& other);
    
    // 3. 拷贝赋值运算符
    ThreeRuleClass& operator=(const ThreeRuleClass& other);
    
    void setValue(int value);
    int getValue() const;
    void printInfo() const;
};

#endif // THREE_RULE_CLASS_H