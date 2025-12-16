### Final Capstone: OOP & STL Systems
* **Focus:** Advanced Architecture & Efficiency
* **Description:** A dual-part final project demonstrating mastery of Object-Oriented hierarchies and Standard Template Library (STL) optimizations.
* **Key Components:**
    * **Library System (`LibrarySystem.cpp`):**
        * Designed a polymorphic class hierarchy (`Item` → `Book`, `Magazine`) using **virtual functions** for dynamic binding.
        * Managed object lifecycles and storage using `std::unordered_map` for efficient retrieval.
    * **Inventory Manager (`InventoryManager.cpp`):**
        * Implemented **O(1)** product lookup using hash maps to optimize search performance.
        * Utilized **Lambda expressions** with `std::sort` to dynamically reorder inventory based on stock levels.
        * Built filtering logic to automatically identify and restock low-quantity items.
* **Usage:**
    ```bash
    cd Final_Exam_OOP_Systems
    # Run Library System
    clang++ -std=c++17 LibrarySystem.cpp -o library_app
    ./library_app

    # Run Inventory Manager
    clang++ -std=c++17 InventoryManager.cpp -o inventory_app
    ./inventory_app
    ```
