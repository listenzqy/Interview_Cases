#include <iostream>
#include <string>

// 三法则反面案例：未正确实现特殊成员函数
class BadResourceHolder {
private:
    std::string name;
    int* data;

public:
    // 构造函数：分配资源
    BadResourceHolder(const std::string& n, int val) : name(n), data(new int(val)) {
        std::cout << "BadResourceHolder 构造函数: " << name << " (资源地址: " << data << ", 值: " << *data << ")" << std::endl;
    }

    // 析构函数：释放资源
    ~BadResourceHolder() {
        std::cout << "BadResourceHolder 析构函数: " << name << " (资源地址: " << data;
        if (data) {
            std::cout << ", 值: " << *data;
        }
        std::cout << ")" << std::endl;
        delete data; // 问题：如果data是悬空指针或已被释放，这里会出问题
        data = nullptr; // 良好实践，但不能解决所有问题
    }

    // 缺失拷贝构造函数 (编译器将生成默认的浅拷贝版本)
    // BadResourceHolder(const BadResourceHolder& other) = default; // 效果类似

    // 缺失拷贝赋值运算符 (编译器将生成默认的浅拷贝版本)
    // BadResourceHolder& operator=(const BadResourceHolder& other) = default; // 效果类似

    void printInfo() const {
        if (data) {
            std::cout << "BadResourceHolder [" << name << "] 数据地址: " << data << ", 值: " << *data << std::endl;
        } else {
            std::cout << "BadResourceHolder [" << name << "] 数据指针为空" << std::endl;
        }
    }

    void setValue(int val) {
        if (data) {
            *data = val;
        } else {
            std::cout << "警告: " << name << " 的数据指针为空，无法设置值。" << std::endl;
        }
    }
};

void demonstrate_shallow_copy_constructor() {
    std::cout << "\n--- 演示浅拷贝构造函数问题 ---\n";
    BadResourceHolder obj1("Obj1", 100);
    obj1.printInfo();

    {
        BadResourceHolder obj2 = obj1; // 调用默认拷贝构造函数 (浅拷贝)
        obj2.name = "Obj2 (copy of Obj1)"; // 修改name以区分，但data指针相同
        std::cout << "在内部作用域创建 Obj2 (Obj1的拷贝):\n";
        obj1.printInfo();
        obj2.printInfo();
        // obj2 即将离开作用域，其析构函数会释放 obj1 和 obj2 共享的 data
    } // obj2 的析构函数被调用，释放了 data

    std::cout << "Obj2 离开作用域后:\n";
    obj1.printInfo(); // obj1.data 现在是悬空指针
    // 尝试使用 obj1.data 可能导致未定义行为或崩溃
    // obj1.setValue(200); // 危险操作！

    // 当 obj1 离开作用域时，其析构函数会尝试再次释放已经被 obj2 释放的内存，导致重复释放错误。
    std::cout << "demonstrate_shallow_copy_constructor 即将结束，Obj1 将被析构...\n";
}

void demonstrate_shallow_copy_assignment() {
    std::cout << "\n--- 演示浅拷贝赋值运算符问题 ---\n";
    BadResourceHolder objA("ObjA", 50);
    BadResourceHolder objB("ObjB", 75);

    std::cout << "赋值前:\n";
    objA.printInfo();
    objB.printInfo();

    objA = objB; // 调用默认拷贝赋值运算符 (浅拷贝)
                 // 1. objA 原本的资源 (值为50的int) 发生内存泄漏，因为没有被释放
                 // 2. objA.data 和 objB.data 现在指向同一个内存地址 (值为75的int)
    objA.name = "ObjA (assigned from ObjB)";

    std::cout << "赋值后:\n";
    objA.printInfo();
    objB.printInfo();

    // 当 objA 和 objB 中任何一个离开作用域并释放资源后，另一个对象的 data 指针将变成悬空指针。
    // 最终会导致重复释放。
    std::cout << "demonstrate_shallow_copy_assignment 即将结束，ObjA 和 ObjB 将被析构...\n";
}


int main() {
    std::cout << "===== 三法则反面案例测试 =====\n";

    // demonstrate_shallow_copy_constructor();
    // demonstrate_shallow_copy_assignment();

    std::cout << "\n===== 测试结束 =====\n";
    // 注意：根据编译器的不同和操作系统的内存管理机制，
    // 重复释放可能直接导致程序崩溃，或者在某些情况下“幸运地”不崩溃但行为仍是未定义的。
    return 0;
}