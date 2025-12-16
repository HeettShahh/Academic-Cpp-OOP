#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
    srand(time(0));
    
    int user_choice;
    int comp_choice = rand() % 20 + 1; // Random number between 1 and 20

    while (true) {
            cout <<"Guess between 1 to 20: ";
            cin >> user_choice;
        if (user_choice == comp_choice) {
            cout << "Correct! You Win!" << endl;
            break;
        } else if (user_choice < comp_choice) {
                cout << "Too Low. Try Again." << endl;
        } else if (user_choice > comp_choice) {
            cout << "Too High. Try Again." << endl;
        } 
    }
    
    return 0;
}