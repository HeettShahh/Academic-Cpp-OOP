#include <iostream>
#include <vector>
#include "my_algorithms.h" // Include your new header

int main() {
    std::cout << " Problem 1: Binary Search Demo" << std::endl;
    std::vector<int> v1 = {1, 3, 5, 7, 9};

    auto it1 = my_binary_search(v1.begin(), v1.end(), 7);
    if (it1 != v1.end()) {
        std::cout << "Found: " << *it1 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    auto it2 = my_binary_search(v1.begin(), v1.end(), 2);
    if (it2 != v1.end()) {
        std::cout << "Found: " << *it2 << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::cout << "\n Problem 2: Remove Duplicates Demo" << std::endl;
    std::vector<int> v2 = {1, 1, 2, 2, 2, 3, 4, 4};
    
    std::cout << "Original: 1 1 2 2 2 3 4 4" << std::endl;
    auto new_end = my_unique(v2.begin(), v2.end());

    std::cout << "After removing duplicates: ";
    for (auto it = v2.begin(); it != new_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}