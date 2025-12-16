### 5. Custom STL Algorithms
* **Focus:** Algorithm Implementation & Iterator Logic
* **Description:** A manual implementation of standard C++ algorithms (`binary_search` and `unique`) using vector iterators.
* **Key Features:**
    * **Binary Search:** Implements O(log n) search logic using iterator arithmetic (`begin + (end - begin) / 2`).
    * **Data Cleaning:** Implements a custom `my_unique` function to remove consecutive duplicates in-place without auxiliary storage.
    * **Iterator Usage:** Demonstrates direct manipulation of `std::vector<int>::iterator` types.
* **Usage:**
    ```bash
    cd 04_Custom_STL_Algorithms
    clang++ main.cpp my_algorithms.cpp -o main -std=c++17
    ./main
    ```
