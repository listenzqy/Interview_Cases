#include "deep_string.h"
#include <iostream>
#include <cstring>

// --- DeepString 类成员函数定义 ---
DeepString::DeepString(const char* s) {
    if (s) {
        len = std::strlen(s);
        data = new char[len + 1];
        std::strcpy(data, s);
        std::cout << "DeepString Constructor for: " << (data ? data : "nullptr")
                  << " (Address: " << static_cast<void*>(data) << ")" << std::endl;
    } else {
        len = 0;
        data = new char[1];
        data[0] = '\0';
        std::cout << "DeepString Constructor for empty string (Address: "
                  << static_cast<void*>(data) << ")" << std::endl;
    }
}

DeepString::~DeepString() {
    std::cout << "DeepString Destructor for: " << (data ? data : "nullptr")
              << " (Address: " << static_cast<void*>(data) << ")" << std::endl;
    if (data) {
        delete[] data;
        data = nullptr;
    }
}

DeepString::DeepString(const DeepString& other) : len(other.len) {
    data = new char[len + 1];
    std::strcpy(data, other.data);
    std::cout << "DeepString Deep Copy Constructor from: " << (other.data ? other.data : "nullptr")
              << " (Original Address: " << static_cast<void*>(other.data) << ")"
              << " to new allocated memory (New Address: " << static_cast<void*>(data) << ")" << std::endl;
}

DeepString& DeepString::operator=(const DeepString& other) {
    std::cout << "DeepString Deep Copy Assignment from: " << (other.data ? other.data : "nullptr")
              << " (Original Address: " << static_cast<void*>(other.data) << ")"
              << " to: " << (data ? data : "nullptr")
              << " (Current Address: " << static_cast<void*>(data) << ")" << std::endl;

    if (this == &other) {
        std::cout << "  Self-assignment detected. No action needed." << std::endl;
        return *this;
    }

    if (data) {
        std::cout << "  Deleting old data at: " << static_cast<void*>(data) << std::endl;
        delete[] data;
    }

    len = other.len;
    data = new char[len + 1];
    std::strcpy(data, other.data);
    std::cout << "  New data allocated at: " << static_cast<void*>(data) << " and content copied." << std::endl;

    return *this;
}

void DeepString::print(const char* name) const {
    std::cout << name << ": \"" << (data ? data : "nullptr") << "\", Address: " << static_cast<void*>(data) << std::endl;
}

void DeepString::modify(const char* new_str) {
    if (new_str) {
        std::cout << "Modifying DeepString (Address: " << static_cast<void*>(data) << ") to: " << new_str << std::endl;
        delete[] data;
        len = std::strlen(new_str);
        data = new char[len + 1];
        std::strcpy(data, new_str);
    }
}

// --- 测试函数定义 ---
void testDeepCopy() {
    std::cout << "\n--- Testing Deep Copy ---" << std::endl;
    DeepString d1("World");
    d1.print("d1 (original)");

    std::cout << "\nCreating d2 using copy constructor from d1..." << std::endl;
    DeepString d2 = d1;
    d1.print("d1 (after d2 copy-constructed)");
    d2.print("d2 (copy of d1)");

    std::cout << "\nModifying d1..." << std::endl;
    d1.modify("Universe");
    d1.print("d1 (modified)");
    d2.print("d2 (after d1 modified - unchanged)");

    std::cout << "\nCreating d3 and using copy assignment..." << std::endl;
    DeepString d3("Initial Deep");
    d3.print("d3 (before assignment)");
    d3 = d1;
    d3.print("d3 (after assignment from d1)");
    d1.print("d1 (after d3 assigned from d1)");

    std::cout << "\n--- End of Deep Copy Test Scope ---" << std::endl;
}