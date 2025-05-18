//
// Created by 11939 on 25-5-18.
//

#include <iostream>
#include "shallow_string.h" // 包含浅拷贝类的头文件
#include "deep_string.h"    // 包含深拷贝类的头文件

int main() {
    std::cout << "****************************************" << std::endl;
    std::cout << "****** DEMONSTRATING SHALLOW COPY ******" << std::endl;
    std::cout << "****************************************" << std::endl;
    try {
        testShallowCopy(); // 调用在 shallow_string.cpp 中定义的测试函数
    } catch (const std::exception& e) {
        std::cerr << "Exception caught during shallow copy test: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught during shallow copy test. Likely due to memory corruption (e.g., double free)." << std::endl;
    }

    std::cout << "\n\n****************************************" << std::endl;
    std::cout << "****** DEMONSTRATING DEEP COPY *******" << std::endl;
    std::cout << "****************************************" << std::endl;
    testDeepCopy(); // 调用在 deep_string.cpp 中定义的测试函数

    std::cout << "\nProgram finished." << std::endl;
    return 0;
}
