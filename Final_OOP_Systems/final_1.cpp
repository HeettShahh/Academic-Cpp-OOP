#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// =======================================================
//                      Item (Base Class)
// =======================================================

class Item {
protected:
    std::string title;
    bool is_out;
    int day_count;

public:
    // Constructor
    Item(std::string t) : title(t), is_out(false), day_count(0) {}

    virtual ~Item() {}

    // availability checker
    bool available() const {
        return (is_out == false);
    }

    void borrow(int days) {
        is_out = true;
        day_count = days;
    }

    // Reset the item
    void give_back() {
        is_out = false;
        day_count = 0;
    }

    // Standard getter
    std::string getTitle() const {
        return title;
    }
    
    // Helper to see days (needed for the list function)
    int getDays() const {
        return day_count;
    }
    virtual std::string info() const = 0;
};

// =======================================================
//                          Book
// =======================================================

class Book : public Item {
private:
    std::string author_name;
    int pub_year;

public:
    // Pass title up to Item, save the rest here
    Book(std::string t, std::string a, int y) 
        : Item(t), author_name(a), pub_year(y) {}

    // Specific string format for Books
    std::string info() const override {
        // Book: <title> by <author> (<year>)
        return "Book: " + title + " by " + author_name + " (" + std::to_string(pub_year) + ")";
    }
};

// =======================================================
//                        Magazine
// =======================================================

class Magazine : public Item {
private:
    int issue_num;

public:
    Magazine(std::string t, int issue) 
        : Item(t), issue_num(issue) {}

    // Specific string format for Magazines
    std::string info() const override {
        // Magazine: <title>, Issue <number>
        return "Magazine: " + title + ", Issue " + std::to_string(issue_num);
    }
};

// =======================================================
//                         Library
// =======================================================

class Library {
private:
    // Using a map to store items. Key = title, Value = item pointer.
    std::unordered_map<std::string, Item*> shelves;

public:
    // Destructor to delete the pointers we created with 'new'
    ~Library() {
        for (auto& entry : shelves) {
            delete entry.second;
        }
    }

    // Add item to the map
    void addItem(Item* item) {
        if (item) {
            shelves[item->getTitle()] = item;
        }
    }

    // Check if key exists and is available
    bool checkAvailability(const std::string& title) {
        if (shelves.count(title) > 0) {
            return shelves[title]->available();
        }
        return false;
    }

    // Logic to borrow an item
    bool borrowItem(const std::string& title, int days) {
        // Try to find the item first
        auto it = shelves.find(title);
        
        // If it exists in the map
        if (it != shelves.end()) {
            Item* target = it->second;
            
            // Only borrow if it's actually free
            if (target->available()) {
                target->borrow(days);
                return true;
            }
        }
        return false;
    }

    // Return logic
    bool returnItem(const std::string& title) {
        auto it = shelves.find(title);
        
        if (it != shelves.end()) {
            Item* target = it->second;
            // Can't return something that isn't borrowed
            if (!target->available()) {
                target->give_back();
                return true;
            }
        }
        return false;
    }

    // Print everything
    void listItems() {
        for (const auto& entry : shelves) {
            Item* current = entry.second;
            
            // Print the info string from the object
            std::cout << current->info() << " - ";
            
            // Print status based on the boolean flag
            if (current->available()) {
                std::cout << "Available" << std::endl;
            } else {
                std::cout << "Borrowed for " << current->getDays() << " days" << std::endl;
            }
        }
    }
};

// =======================================================
//                      main(): test
// =======================================================

int main() {
    Library lib;

    // ----- Add Items -----
    lib.addItem(new Book("The Hobbit", "Tolkien", 1937));
    lib.addItem(new Book("Clean Code", "Martin", 2008));
    lib.addItem(new Magazine("Science Weekly", 42));

    std::cout << "--- Initial Items ---\n";
    lib.listItems();

    // ----- Check Availability -----
    std::cout << "\nChecking availability of 'Clean Code': ";
    std::cout << (lib.checkAvailability("Clean Code") ? "Available\n" : "Not available\n");

    // ----- Borrow Success -----
    std::cout << "\nBorrowing 'Clean Code' for 5 days...\n";
    bool ok = lib.borrowItem("Clean Code", 5);
    std::cout << (ok ? "Borrow successful.\n" : "Borrow failed.\n");
    lib.listItems();

    // ----- Borrow Fail (already borrowed) -----
    std::cout << "\nTrying to borrow 'Clean Code' again...\n";
    ok = lib.borrowItem("Clean Code", 3);
    std::cout << (ok ? "Borrow successful.\n" : "Borrow failed.\n");

    // ----- Return Success -----
    std::cout << "\nReturning 'Clean Code'...\n";
    ok = lib.returnItem("Clean Code");
    std::cout << (ok ? "Return successful.\n" : "Return failed.\n");
    lib.listItems();

    // ----- Return Fail (not borrowed) -----
    std::cout << "\nTrying to return 'Clean Code' again...\n";
    ok = lib.returnItem("Clean Code");
    std::cout << (ok ? "Return successful.\n" : "Return failed.\n");

    // ----- Check availability again -----
    std::cout << "\nChecking availability of 'Clean Code' again: ";
    std::cout << (lib.checkAvailability("Clean Code") ? "Available\n" : "Not available\n");

    return 0;
}