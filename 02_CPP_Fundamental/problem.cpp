#include <iostream> 

size_t myStrlen(const char* s) {
    size_t length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src; 
        dest++;
        src++;
    }
    *dest = '\0'; 
}

int main() {
    const char* original_string = "UAB-CS";

    char copied_string[50];

    std::cout << "Input string: " << original_string << std::endl;

    size_t length = myStrlen(original_string);
    std::cout << "myStrlen: " << length << std::endl;

    myStrcpy(copied_string, original_string);

    std::cout << "After myStrcpy, destination string: " << copied_string << std::endl;

    return 0;
}