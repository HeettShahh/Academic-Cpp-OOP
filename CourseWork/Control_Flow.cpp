#include <iostream>

int main() {
    
    // switch
    // char op; // '+', '-', '*', '/'
    // int a,b;
    // std::cout << "enter the values for a op b:" << std::endl;
    // std::cin >> a >> op >> b;
    
    // int result;

    // switch (op) {
    //     case '+': result = a+b; break;
    //     case '-': result = a-b; break;
    //     case '*': result = a*b; break;
    //     case '/': result = a/b; break;
    //     default: std::cout << "operation is not supported" <<std::endl;
    // };

    // std::cout << result << std::endl;

    // nested for loop
    // 5 * 5 multiplication table
    for (int i = 1; i < 6; i++){
        for (int j = 1; j <= i; j++){
            std::cout << i * j << '\t';
        };
        std::cout << std::endl;
    };
    
    return 0;
}