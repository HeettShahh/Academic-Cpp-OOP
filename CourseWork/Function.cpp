#include <iostream>

int Multiply(int a, int b) {
    return a * b;
}

void PrintHelloWorld() {
    std::cout << "Hello, World!" << std::endl;
}

void MultiplyAndPrint(int a, int b) {
    int product = Multiply(a, b);
    std::cout << "Product: " << product << std::endl;
}

int main() {
    PrintHelloWorld();

    int product = Multiply(2, 3);
    std::cout << "Product: " << product << std::endl;

    int product2 = Multiply(4, 5);
    std::cout << "Product2: " << product2 << std::endl;

    int product3 = Multiply(6, 7);
    std::cout << "Product3: " << product3 << std::endl;

    MultiplyAndPrint(2, 3);
    MultiplyAndPrint(4, 5);
    MultiplyAndPrint(6, 7);

    return 0;
}

int myFunction(){
    return 0;
}

int main() {
// auto return 0; 
}