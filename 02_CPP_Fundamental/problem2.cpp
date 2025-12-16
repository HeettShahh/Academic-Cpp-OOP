#include <iostream>
#include <string>  

int countChar(const std::string& s, char target) {
    int count = 0;
    for (char c : s) {
        if (c == target) {
            count++;
        }
    }
    return count;
}

int countChar(const char* s, char target) {
    int count = 0;

    while (*s != '\0') {
        if (*s == target) {
            count++;
        }
        s++;
    }
    return count;
}

int main() {
    std::string test_string = "UAB-CS-UAB";
    char char_to_find = 'A';

    std::cout << "Enter a string: " << test_string << std::endl;
    std::cout << "Enter a character to count: " << char_to_find << std::endl;

    int result_v1 = countChar(test_string, char_to_find);
    std::cout << "std::string version: " << result_v1 << std::endl;

    int result_v2 = countChar(test_string.c_str(), char_to_find);
    std::cout << "C-style string version: " << result_v2 << std::endl;

    return 0;
}