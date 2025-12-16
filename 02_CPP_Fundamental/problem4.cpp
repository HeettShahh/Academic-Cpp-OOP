#include <iostream>
#include <string>
#include <limits> 

struct Contact {
    std::string name;
    std::string phone;
    int age;
};

void addContact(Contact contacts[], int& count) {
    if (count >= 10) {
        std::cout << "Address book is full." << std::endl;
        return;
    }

    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, contacts[count].name);

    std::cout << "Enter phone: ";
    std::getline(std::cin, contacts[count].phone);
    
    std::cout << "Enter age: ";
    std::cin >> contacts[count].age;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    count++;
    std::cout << "Contact added." << std::endl;
}

void listContacts(const Contact contacts[], int count) {
    if (count == 0) {
        std::cout << "Address book is empty." << std::endl;
        return;
    }
    std::cout << "\n--- All Contacts ---\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << contacts[i].name 
                  << ", Phone: " << contacts[i].phone 
                  << ", Age: " << contacts[i].age << std::endl;
    }
    std::cout << "--------------------\n";
}

void deleteContact(Contact contacts[], int& count, const std::string& name) {
    int found_index = -1;
    for (int i = 0; i < count; ++i) {
        if (contacts[i].name == name) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        std::cout << "Contact not found." << std::endl;
    } else {
        for (int i = found_index; i < count - 1; ++i) {
            contacts[i] = contacts[i + 1];
        }
        count--;
        std::cout << "Contact deleted." << std::endl;
    }
}

void searchByName(const Contact contacts[], int count, const std::string& name) {
    for (int i = 0; i < count; ++i) {
        if (contacts[i].name == name) {
            std::cout << "Contact found:" << std::endl;
            std::cout << "Name: " << contacts[i].name 
                      << ", Phone: " << contacts[i].phone 
                      << ", Age: " << contacts[i].age << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

int main() {
    Contact contacts[10]; 
    int count = 0;
    int choice;

    do {
        std::cout << "\nMenu:\n"
             << "1. Add contact\n"
             << "2. Delete contact\n"
             << "3. List contacts\n"
             << "4. Search by name\n"
             << "0. Exit\nChoice: ";
        
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        if (choice == 1) {
            addContact(contacts, count);
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter name to delete: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);
            deleteContact(contacts, count, name);
        } else if (choice == 3) {
            listContacts(contacts, count);
        } else if (choice == 4) {
            std::string name;
            std::cout << "Enter name to search: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);
            searchByName(contacts, count, name);
        }
    } while (choice != 0);

    return 0;
}