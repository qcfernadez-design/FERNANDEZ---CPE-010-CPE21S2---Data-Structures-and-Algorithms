#include <iostream>
#include <string>

//Classes
class Fruit {
private:
    std::string* name;
    double* price;
    int* quantity;

public:
    // Constructor
    Fruit(std::string newName = "Fruit_Item", double newPrice = 0.0, int newQuantity = 0) {
        name = new std::string(newName);
        price = new double(newPrice);
        quantity = new int(newQuantity);
        std::cout << "[Fruit] Constructor called for " << *name << std::endl;
    }

    // Destructor
    ~Fruit() {
        if (name) std::cout << "Fruit Destructor called for " << *name << std::endl;
        delete name;
        delete price;
        delete quantity;
    }

    // Copy Constructor
    Fruit(const Fruit& other) {
        name = new std::string(*other.name);
        price = new double(*other.price);
        quantity = new int(*other.quantity);
        std::cout << "Fruit Copy Constructor called." << std::endl;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            delete name;
            delete price;
            delete quantity;

            name = new std::string(*other.name);
            price = new double(*other.price);
            quantity = new int(*other.quantity);
        }
        std::cout << "Fruit Copy Assignment Operator called." << std::endl;
        return *this;
    }

    void displayDetails() const {
        std::cout << "Category: Fruit = " << *name << " - PHP " << *price << " x " << *quantity << std::endl;
    }

    double calculateSum() const {
        return (*price) * (*quantity);
    }
};

class Vegetable {
private:
    std::string* name;
    double* price;
    int* quantity;

public:
    // Constructor
    Vegetable(std::string newName = "Veggie_Item", double newPrice = 0.0, int newQuantity = 0) {
        name = new std::string(newName);
        price = new double(newPrice);
        quantity = new int(newQuantity);
        std::cout << "Vegetable Constructor called for " << *name << std::endl;
    }

    // Destructor
    ~Vegetable() {
        if (name) std::cout << "Vegetable Destructor called for " << *name << std::endl;
        delete name;
        delete price;
        delete quantity;
    }

    // Copy Constructor
    Vegetable(const Vegetable& other) {
        name = new std::string(*other.name);
        price = new double(*other.price);
        quantity = new int(*other.quantity);
        std::cout << "Vegetable Copy Constructor called." << std::endl;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            delete name;
            delete price;
            delete quantity;

            name = new std::string(*other.name);
            price = new double(*other.price);
            quantity = new int(*other.quantity);
        }
        std::cout << "Vegetable Copy Assignment Operator called." << std::endl;
        return *this;
    }

    void displayDetails() const {
        std::cout << "Category: Vegetable = " << *name << " - PHP " << *price << " x " << *quantity << std::endl;
    }

    double calculateSum() const {
        return (*price) * (*quantity);
    }

    std::string getName() const {
        return *name;
    }
};

// --- Problem 3: Function TotalSum ---
double TotalSum(Fruit* fruits[], int fruitCount, Vegetable* veggies[], int veggieCount) {
    double total = 0.0;
    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != nullptr) {
            total += fruits[i]->calculateSum();
        }
    }
    for (int i = 0; i < veggieCount; i++) {
        if (veggies[i] != nullptr) {
            total += veggies[i]->calculateSum();
        }
    }
    return total;
}
//Main Driver
int main() {
    //Lists for Fruits and Vegetables
    Fruit* fruitList[2];
    fruitList[0] = new Fruit("Apple", 10.0, 7);
    fruitList[1] = new Fruit("Banana", 10.0, 8);

    Vegetable* veggieList[2];
    veggieList[0] = new Vegetable("Broccoli", 60.0, 12);
    veggieList[1] = new Vegetable("Lettuce", 50.0, 10);

    std::cout << "      Displaying Grocery List Items      " << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitList[i] != nullptr) fruitList[i]->displayDetails();
    }
    for (int i = 0; i < 2; i++) {
        if (veggieList[i] != nullptr) veggieList[i]->displayDetails();
    }

    // Calculator for the Grand Total
    double grandTotal = TotalSum(fruitList, 2, veggieList, 2);
    std::cout << "Total Sum of all items: PHP " << grandTotal << "\n\n";

    //Specifically Deletes the lettuc and de-allocate its memory
    for (int i = 0; i < 2; i++) {
        if (veggieList[i] != nullptr && veggieList[i]->getName() == "Lettuce") {
            delete veggieList[i];
            veggieList[i] = nullptr; // Clear pointer to prevent dangling reference
            std::cout << "Lettuce memory successfully de-allocated and deleted.\n";
        }
    }

    // The section the deletes remaining objects
    for (int i = 0; i < 2; i++) {
        if (fruitList[i] != nullptr) {
            delete fruitList[i];
            fruitList[i] = nullptr;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (veggieList[i] != nullptr) {
            delete veggieList[i];
            veggieList[i] = nullptr;
        }
    }

    return 0;
}