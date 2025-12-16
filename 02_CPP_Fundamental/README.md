### 2. C++ Fundamentals Collection
* **Focus:** Low-Level Data Manipulation & Language Mechanics
* **Description:** A suite of four foundational C++ programs demonstrating manual implementation of standard library features.
* **Key Components:**
    * **Custom String Lib (`problem.cpp`):** Recreates `strlen` and `strcpy` using raw pointer arithmetic (`*s++`) to manipulate C-style strings manually.
    * **Function Overloading (`problem2.cpp`):** Demonstrates C++ polymorphism by implementing `countChar` for both `std::string` and `char*` types.
    * **Array Statistics (`problem3.cpp`):** Performs statistical analysis (Max, Average) and in-place reversal on raw integer arrays.
    * **Address Book (`problem4.cpp`):** A CRUD application using an array of `struct Contact` objects, handling input buffers and edge cases.
* **Usage:**
    ```bash
    cd 02_CPP_Fundamentals
    clang++ problem4.cpp -o address_book
    ./address_book
    ```
