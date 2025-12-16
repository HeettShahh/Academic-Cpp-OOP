#include <iostream>

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findMax(const int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

double computeAverage(const int arr[], int size) {
    double sum = 0.0; 
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

    std::cout << "Enter 10 integers: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << "Max: " << findMax(numbers, SIZE) << std::endl;

    std::cout << "Average: " << computeAverage(numbers, SIZE) << std::endl;

    reverseArray(numbers, SIZE);

    std::cout << "Reversed array: ";
    printArray(numbers, SIZE);

    return 0;
}