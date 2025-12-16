#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() { 
    srand(time(0));

    int comp_choice = rand() % 3; // 0-Rock, 1-Paper, 2-Scissors
    int user_choice;

    while (true) {
    cout << "Enter 0 (Rock), 1(Paper), or 2 (Scissors): ";
    cin >> user_choice;

        if (user_choice >= 0 && user_choice <=2) {
            break;
        } else {
            cout << "Invalid Input. Try Again." << endl;
        }
    }
    
    cout << "Computer choice: " << comp_choice << endl;

    if (user_choice == comp_choice) {
        cout << " It's a tie" << endl;
    } else if (user_choice == 0 && comp_choice == 2 || 
               user_choice == 1 && comp_choice == 0 || 
               user_choice == 2 && comp_choice == 1) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}