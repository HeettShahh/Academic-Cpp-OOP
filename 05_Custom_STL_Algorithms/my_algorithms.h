#ifndef MY_ALGORITHMS_H
#define MY_ALGORITHMS_H

#include <vector>
// Define the iterator type

using IntIterator = std::vector<int>::iterator;

// Problem 1: Binary Search Declaration
IntIterator my_binary_search(IntIterator begin, IntIterator end, int target);

//Problem 2: Remove Consecutive Duplicates Declaration
IntIterator my_unique(IntIterator begin, IntIterator end);

#endif