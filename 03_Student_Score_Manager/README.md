### 3. Student Score Manager (Memory Management Lab)
* **Focus:** Dynamic Memory Allocation & Safety
* **Description:** A utility for tracking student scores that manually manages memory on the heap. This project serves as a practical study of pointer safety, specifically analyzing the effects of memory leaks and dangling pointers.
* **Key Features:**
    * **Dynamic Allocation:** Uses `new int[n]` to handle user-defined array sizes at runtime.
    * **Memory Safety:** Implements proper cleanup using `delete[]` to prevent memory leaks.
    * **Undefined Behavior Research:** Documented experiments on the behavior of dereferencing dangling pointers and the instability caused by missing delete commands.
* **Usage:**
    ```bash
    cd 05_Student_Score_Manager
    clang++ main.cpp -o student_score_manager
    ./student_score_manager
    ```
