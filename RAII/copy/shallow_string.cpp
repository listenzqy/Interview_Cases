#include "shallow_string.h"
#include <iostream>
#include <cstring>

// --- ShallowString 类成员函数定义 ---
ShallowString::ShallowString(const char* s) {
    if (s) {
        len = std::strlen(s);
        data = new char[len + 1];
        std::strcpy(data, s);
        std::cout << "ShallowString Constructor for: " << (data ? data : "nullptr")
                  << " (Address: " << static_cast<void*>(data) << ")" << std::endl;
    } else {
        len = 0;
        data = new char[1];
        data[0] = '\0';
        std::cout << "ShallowString Constructor for empty string (Address: "
                  << static_cast<void*>(data) << ")" << std::endl;
    }
}

ShallowString::~ShallowString() {
    std::cout << "ShallowString Destructor for: " << (data ? data : "nullptr")
              << " (Address: " << static_cast<void*>(data) << ")" << std::endl;
    if (data) {
        delete[] data;
        data = nullptr;
    }
}

ShallowString::ShallowString(const ShallowString& other) : len(other.len) {
    data = other.data; // 关键点：仅仅复制了指针地址
    std::cout << "ShallowString Shallow Copy Constructor from: " << (other.data ? other.data : "nullptr")
              << " to: " << (data ? data : "nullptr")
              << " (Copied Address: " << static_cast<void*>(data) << ")" << std::endl;
}

ShallowString& ShallowString::operator=(const ShallowString& other) {
    std::cout << "ShallowString Shallow Copy Assignment from: " << (other.data ? other.data : "nullptr")
              << " to: " << (data ? data : "nullptr") << std::endl;
    if (this == &other) {
        return *this;
    }
    // 注意：内存泄漏和悬挂指针风险
    data = other.data;
    len = other.len;
    std::cout << "  (Assigned Address: " << static_cast<void*>(data) << ")" << std::endl;
    return *this;
}

void ShallowString::print(const char* name) const {
    std::cout << name << ": \"" << (data ? data : "nullptr") << "\", Address: " << static_cast<void*>(data) << std::endl;
}

void ShallowString::modify(const char* new_str) {
    if (data && new_str) {
        std::cout << "Modifying ShallowString (Address: " << static_cast<void*>(data) << ") to: " << new_str << std::endl;
        std::strncpy(data, new_str, len); // 假设 new_str 长度小于等于原 len
        if (len > 0 && (size_t)len > std::strlen(new_str)) { // 确保字符串结束符正确
             data[std::strlen(new_str)] = '\0';
        } else if (len > 0) {
            data[len] = '\0'; // 如果 new_str 填满了，确保末尾是 '\0'
        }
    }
}

// --- 测试函数定义 ---
void testShallowCopy() {
    std::cout << "\n--- Testing Shallow Copy ---" << std::endl;
    ShallowString s1("Hello");
    s1.print("s1 (original)");

    std::cout << "\nCreating s2 using copy constructor from s1..." << std::endl;
    ShallowString s2 = s1;
    s1.print("s1 (after s2 copy-constructed)");
    s2.print("s2 (copy of s1)");

    std::cout << "\nModifying s1..." << std::endl;
    s1.modify("Hi");
    s1.print("s1 (modified)");
    s2.print("s2 (after s1 modified - also changed!)");

    std::cout << "\nCreating s3 and using copy assignment..." << std::endl;
    ShallowString s3("Initial");
    s3.print("s3 (before assignment)");
    s3 = s1;
    s3.print("s3 (after assignment from s1)");
    s1.print("s1 (after s3 assigned from s1)");

    std::cout << "\n--- End of Shallow Copy Test Scope ---" << std::endl;
}