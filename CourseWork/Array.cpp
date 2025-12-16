#include <iostream>
// #include <string>
// using namespace std

int main() {

    int arr[3] = {1, 2, 3};
    int* ptr = arr;

    std::cout << arr[2] << std::endl;
    std::cout << *(ptr+2) << std::endl;

    *(ptr+3) = 10;  // no safety checking

    // std::string a = "A";
    
    return 0;
}