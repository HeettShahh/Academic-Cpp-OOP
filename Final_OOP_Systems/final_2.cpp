#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

// struct Product
struct Product {
    std::string name;
    int quantity;
    double price;
};

// Helper: print products
void printProducts(const std::vector<Product>& products, const std::string& title) {
    std::cout << "--- " << title << " ---\n";
    for (const auto& p : products) {
        std::cout << p.name
                  << " (qty=" << p.quantity
                  << ", price=" << p.price << ")\n";
    }
    std::cout << std::endl;
}

// ========================= 1. Initialization =========================

void initializeInventory(std::vector<Product>& products,
                         std::unordered_map<std::string, int>& nameToIndex) 
{
    // Make sure we start fresh
    products.clear();
    nameToIndex.clear();

    // Fill the vector with the exam data
    products = {
        {"Apple", 50, 1.29},
        {"Milk", 8, 2.99},
        {"Bread", 12, 2.49},
        {"Eggs", 24, 3.99},
        {"Cheese", 5, 4.59},
        {"Chicken", 15, 7.99},
        {"Orange", 10, 1.19},
        {"Banana", 30, 0.79}
    };

    // Build the hash map: Product Name -> Vector Index
    // doing this loop to map every item
    for (int k = 0; k < products.size(); ++k) {
        nameToIndex[products[k].name] = k;
    }
}


// ========================= 2. Fast item lookup =========================

Product* findProduct(const std::string& name,
                     std::vector<Product>& products,
                     std::unordered_map<std::string, int>& nameToIndex)
{
    // Try to find the name in the map
    auto result = nameToIndex.find(name);
    
    // check if we actually found something
    if (result != nameToIndex.end()) {
        int idx = result->second; // get the index
        return &products[idx];    // return address of the item
    }
    
    // return null if name doesn't exist
    return nullptr;
}


// ========================= 3. Low-stock products =========================

std::vector<Product> filter_lower(const std::vector<Product>& products, int limit) {
    std::vector<Product> low_items;
    
    // scan through the whole inventory
    for (const auto& item : products) {
        // if quantity is below the limit, add to our list
        if (item.quantity < limit) {
            low_items.push_back(item);
        }
    }
    
    return low_items;
}


// ========================= 4. Sort =========================

void sortAndRefresh(std::vector<Product>& products,
                    std::unordered_map<std::string, int>& nameToIndex)
{
    // Sort logic: using lambda to compare quantities
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.quantity < b.quantity;
    });

    // The vector order changed, so the map indices are wrong now.
    // Need to clear and rebuild the map.
    nameToIndex.clear();
    for (int i = 0; i < products.size(); ++i) {
        nameToIndex[products[i].name] = i;
    }
}


// ========================= 5. Increase stock =========================

void restockProducts(const std::vector<Product>& items_to_add,
                     int amount,
                     std::vector<Product>& products,
                     std::unordered_map<std::string, int>& nameToIndex)
{
    // Loop specifically through the low stock items
    for (const auto& short_item : items_to_add) {
        
        // Find the real item in the main list
        Product* ptr = findProduct(short_item.name, products, nameToIndex);
        
        // update the count if found
        if (ptr != nullptr) {
            ptr->quantity += amount;
        }
    }
}


int main() {
    std::vector<Product> products;
    std::unordered_map<std::string, int> nameToIndex;

    // 1. Initialization
    initializeInventory(products, nameToIndex);
    printProducts(products, "Initial inventory");

    // Show the name-to-index map
    std::cout << "--- Name to Index Map ---\n";
    for (const auto& pair : nameToIndex) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }
    std::cout << std::endl;

    // 2. Fast item lookup demo
    std::cout << "--- Fast item lookup demo ---\n";
    const std::string lookupName1 = "Milk";
    const std::string lookupName2 = "Unknown";

    if (Product* p = findProduct(lookupName1, products, nameToIndex)) {
        std::cout << "Found " << lookupName1
                  << ": qty=" << p->quantity
                  << ", price=" << p->price << "\n";
    } else {
        std::cout << lookupName1 << " not found.\n";
    }

    if (Product* p = findProduct(lookupName2, products, nameToIndex)) {
        std::cout << "Found " << lookupName2
                  << ": qty=" << p->quantity
                  << ", price=" << p->price << "\n";
    } else {
        std::cout << lookupName2 << " not found.\n";
    }
    std::cout << std::endl;

    // 3. Low-stock products (threshold = 10)
    auto lowStock = filter_lower(products, 10);
    printProducts(lowStock, "Low-stock products (quantity < 10)");

    // 4. Sort by quantity (ascending)
    sortAndRefresh(products, nameToIndex);
    printProducts(products, "Inventory sorted by quantity (ascending)");

    // 5. Increase stock for low-stock products (e.g., +20 each)
    restockProducts(lowStock, 20, products, nameToIndex);
    printProducts(products, "Inventory after restocking");

    return 0;
}