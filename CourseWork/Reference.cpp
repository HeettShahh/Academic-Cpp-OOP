#include <iostream>

// void increment(int x){
//     ++x;
// }

// void increment(int& x){
//     ++x;
// }

void increment(int* ptr){
    // ++(*ptr);
    (*ptr)++;
}

int main() {

    // int a = 0;
    // std::cout << a << std::endl;
    // increment(&a);
    // std::cout << a << std::endl;

    int a = 10;
    int b = 20;
    int& ref = a;

    std::cout << a << ref << b << std::endl;

    ref = b;
    std::cout << a << ref << b << std::endl;

    return 0;
}