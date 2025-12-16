#include <iostream>
using namespace std;

double average(int* arr, int n);
int maximum(int* arr, int n);
int minimum(int* arr, int n);

// Definitions
double average(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    return static_cast<double>(sum) / n;
}

int maximum(int* arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int minimum(int* arr, int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    // 1. Dynamic allocation 
    int* scores = new int[n];

    // 2. Input output
    cout << "Enter " << n << " student scores:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
    }

    // Output scores
    cout << "\nStudent Scores: ";
    for (int i = 0; i < n; ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // 3. Avg, Max, Min
    cout << "Average score: " << average(scores, n) << endl;
    cout << "Maximum score: " << maximum(scores, n) << endl;
    cout << "Minimum score: " << minimum(scores, n) << endl;

    // 4. Memory Leak Experiment
    delete[] scores;
    /* When delete[] is not used,
    The behavior was irregular; sometimes it would print a random number, 
    sometimes it would crash or show nothing wrong — 
    undefined behavior.
    */



    /* 
    5. Dangling Pointer Experiment
    cout << scores[0];
    scores = nullptr after delete[].
    */

    scores = nullptr;
    return 0;

    /*
    The output was inconsistent − sometimes it prints out a random number, 
    crashes, appears to "run" without apparently crashing 
    (but the next execution is not guaranteed to work because it is undefined). 

    the pointer would not be (most of the time) dereferencing into a invalid memory, 
    and if the pointer is dereferencing from a nullptr, there is no undefined behavior to now dereference it again in the future 
    */

}