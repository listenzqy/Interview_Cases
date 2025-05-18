#include <iostream>
#include "ZeroRuleClass.h"
#include "ThreeRuleClass.h"
#include "FiveRuleClass.h"

// 测试函数
void testZeroRule() {
    std::cout << "\n===== 零法则测试 =====\n";
    
    ZeroRuleClass obj1("对象1");
    obj1.addData(10);
    obj1.addData(20);
    obj1.printInfo();
    
    // 测试拷贝
    ZeroRuleClass obj2 = obj1;  // 拷贝构造
    obj2.printInfo();
    
    ZeroRuleClass obj3("对象3");
    obj3 = obj1;  // 拷贝赋值
    obj3.printInfo();
}

void testThreeRule() {
    std::cout << "\n===== 三法则测试 =====\n";
    
    ThreeRuleClass obj1("对象1");
    obj1.setValue(100);
    obj1.printInfo();
    
    // 测试拷贝构造
    ThreeRuleClass obj2 = obj1;
    obj2.printInfo();
    obj2.setValue(200);
    
    // 验证深拷贝
    std::cout << "修改obj2后:" << std::endl;
    obj1.printInfo();
    obj2.printInfo();
    
    // 测试拷贝赋值
    ThreeRuleClass obj3("对象3");
    obj3 = obj1;
    obj3.printInfo();
}

void testFiveRule() {
    std::cout << "\n===== 五法则测试 =====\n";
    
    FiveRuleClass obj1("对象1");
    obj1.setValue(100);
    obj1.printInfo();
    
    // 测试拷贝构造
    FiveRuleClass obj2 = obj1;
    obj2.printInfo();
    
    // 测试移动构造
    FiveRuleClass obj3 = std::move(obj1);
    std::cout << "移动后的源对象: ";
    obj1.printInfo();  // 源对象已被移动，resource应为nullptr
    obj3.printInfo();
    
    // 测试移动赋值
    FiveRuleClass obj4("对象4");
    obj4 = std::move(obj2);
    std::cout << "移动赋值后的源对象: ";
    obj2.printInfo();  // 源对象已被移动，resource应为nullptr
    obj4.printInfo();
}

int main() {
    std::cout << "C++三法则、五法则、零法则测试\n";
    std::cout << "============================\n";
    
    testZeroRule();
    testThreeRule();
    testFiveRule();
    
    std::cout << "\n所有测试完成\n";
    return 0;
}