#include "my_algorithms.h"

// Problem 1: Binary Search Definition
IntIterator my_binary_search(IntIterator begin, IntIterator end, int target) {
    IntIterator left = begin;
    IntIterator right = end;

    while (left < right) {
        IntIterator mid = left + (right - left) / 2;
        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return end;
}

// Problem 2: Remove Consecutive Duplicates Definition
IntIterator my_unique(IntIterator begin, IntIterator end) {
    if (begin == end) {
        return end;
    }

    IntIterator write_it = begin;
    IntIterator read_it = begin;
    ++read_it;

    while (read_it != end) {
        if (*read_it != *write_it) {
            ++write_it;
            *write_it = *read_it;
        }
        ++read_it;
    }
    return ++write_it;
}