#ifndef FIVE_RULE_CLASS_H
#define FIVE_RULE_CLASS_H

#include <string>

// 五法则示例：增加移动语义支持
class FiveRuleClass {
private:
    std::string name;
    int* resource;

public:
    // 构造函数
    FiveRuleClass(const std::string& n);
    
    // 1. 析构函数
    ~FiveRuleClass();
    
    // 2. 拷贝构造函数
    FiveRuleClass(const FiveRuleClass& other);
    
    // 3. 拷贝赋值运算符
    FiveRuleClass& operator=(const FiveRuleClass& other);
    
    // 4. 移动构造函数
    FiveRuleClass(FiveRuleClass&& other) noexcept;
    
    // 5. 移动赋值运算符
    FiveRuleClass& operator=(FiveRuleClass&& other) noexcept;
    
    void setValue(int value);
    int getValue() const;
    void printInfo() const;
};

#endif // FIVE_RULE_CLASS_H