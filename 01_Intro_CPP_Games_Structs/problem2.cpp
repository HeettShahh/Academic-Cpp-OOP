#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    int user_choice; 
    int n = 50;

    while (true) {
        cout << "Enter a number between 1 and 50: " ;
        cin >> user_choice;
        if (user_choice >= 1 && user_choice <= n) {
            break;
        } else {
            cout << "Invalid Input. Try Again." << endl;
        }
    }

    for (int i = 1; i <= user_choice; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz ";
        } else if (i % 5 == 0) {
            cout << "Buzz ";
        } else if (i % 3 == 0) {
            cout << "Fizz ";
        } else {
            cout << i << " ";
        }
    }



    return 0;
}