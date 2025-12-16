#include <iostream>

int main() {

    int var = 8;
    int* ptr = &var;

    std::cout << var << std::endl;
    std::cout << ptr << std::endl;
    std::cout << sizeof(var) << std::endl;
    std::cout << sizeof(ptr) << std::endl;

    // char var2 = 'a';
    // char* ptr2 = &var2;
    // std::cout << var2 << std::endl;
    // std::cout << ptr2 << std::endl;
    // std::cout << sizeof(var2) << std::endl;
    // std::cout << sizeof(ptr2) << std::endl;

    double var3 = 1.2;
    double* ptr3 = &var3;
    std::cout << var3 << std::endl;
    std::cout << *ptr3 << std::endl;
    std::cout << sizeof(var3) << std::endl;
    std::cout << sizeof(ptr3) << std::endl;

    return 0;
}