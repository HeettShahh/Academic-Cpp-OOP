#include <iostream>

int main() {

    int myVariable = 42; // Declare an integer variable and initialize it
    int anotherVariable; // Declare another integer variable without initializing it
    std::cout << myVariable << std::endl;
    std::cout << anotherVariable << std::endl; // This may print a garbage value
    anotherVariable = 100; // Initialize the second variable
    std::cout << anotherVariable << std::endl; // Now it will print the initialized value
    myVariable = 58; // Change the value of the first variable
    std::cout << myVariable << std::endl; // Print the changed value

    std::cout << "Size of myVariable: " << sizeof(myVariable) << " bytes" << std::endl;
    std::cout << "Size of anotherVariable: " << sizeof(anotherVariable) << " bytes" << std::endl;

    int myVariable = -58;
    std::cout << myVariable << std::endl;
    unsigned int unsignedVar = -58;
    std::cout << unsignedVar << std::endl;
    /*
    58: 00000000 00000000 00000000 00111010
    complement code: 11111111 11111111 11111111 11000101
    it's 4294967238
    */ 

    char myChar = 'A';
    std::cout << myChar << std::endl;
    char anotherChar = 65;
    std::cout << anotherChar << std::endl;
    std::cout << (int)(myChar) << std::endl;
    short myShort = 'A';
    std::cout << myShort << std::endl;

    float myFloat = 5.5;
    double myDouble = 10.5;
    std::cout << sizeof(myFloat) << std::endl;
    std::cout << sizeof(myDouble) << std::endl;
    myFloat = 5.5f;
    std::cout << sizeof(myFloat) << std::endl;

    bool myBool = true;
    std::cout << sizeof(myBool) << std::endl;
    std::cout << myBool << std::endl;
    myBool = false;
    std::cout << myBool << std::endl;
    myBool = 100;
    std::cout << myBool << std::endl;

    struct Student {
        int id;  // 4 bytes
        char grade;  // 1 byte
        float gpa;  // 4 bytes
    };

    Student s1, s2;
    s1.id = 1001;
    s1.grade = 'A';
    s1.gpa = 3.5f;

    std::cout << "ID: " << s1.id << std::endl;
    std::cout << "Grade: " << s1.grade << std::endl;
    std::cout << "GPA: " << s1.gpa << std::endl;

    std::cout << "Size of Student struct: " << sizeof(s1) << " bytes" << std::endl;

    return 0;
}