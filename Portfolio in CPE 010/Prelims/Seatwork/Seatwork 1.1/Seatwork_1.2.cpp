#include <iostream>
using namespace std;

int main() {
    
    //Stores the values 
    string Item1;
    string Item2;
    string Item3;
    int price1;
    int price2;
    int price3;
    int choice1;
    int choice2;
    int choice3;
    int Total;
    int pay;
    
    cout << "Welcome! Please choose 3 items of your choice to purchase." << endl << endl;
    cout << "1.) Apple 30?" << endl << "2.) Orange 24?" << endl << "3.) Pineapple 68?" << endl << "4.) Watermelon 86?" << endl << "5.) Mango 50?" << endl << endl;
    
    //Gets the value for choices 1, 2, and 3
    cout << "Please input from 1-5: ";
    cin >> choice1;
    
    switch (choice1) {
        case 1: price1 = 30; 
        Item1 = "Apple";
        break;
        case 2: price1 = 24;
        Item1 = "Orange";
        break;
        case 3: price1 = 68; 
        Item1 = "Pineapple";
        break;
        case 4: price1 = 86; 
        Item1 = "Watermelon";
        break;
        case 5: price1 = 50; 
        Item1 = "Mango";
        break;
        
        // Is the default outcome when users inputs a value other then the numbers 1-5
        default: cout << "Invalid Input please try again and choose from 1-5";
        return 0;
    }
    
    cout << "Please input from 1-5: ";
    cin >> choice2;
    switch (choice2) {
        case 1: price2 = 30; 
        Item2 = "Apple";
        break;
        case 2: price2 = 24;
        Item2 = "Orange";
        break;
        case 3: price2 = 68; 
        Item2 = "Pineapple";
        break;
        case 4: price2 = 86; 
        Item2 = "Watermelon";
        break;
        case 5: price2 = 50; 
        Item2 = "Mango";
        break;
        
        default: cout << "Invalid Input please try again and choose from 1-5";
        return 0;
    
    }
    
    cout << "Please input from 1-5: ";
    cin >> choice3;
    cout << " " << endl << endl;
    switch (choice3) {
        case 1: price3 = 30; 
        Item3 = "Apple";
        break;
        case 2: price3 = 24;
        Item3 = "Orange";
        break;
        case 3: price3 = 68; 
        Item3 = "Pineapple";
        break;
        case 4: price3 = 86; 
        Item3 = "Watermelon";
        break;
        case 5: price3 = 50; 
        Item3 = "Mango";
        break;
        
        default: cout << "Invalid Input please try again and choose from 1-5";
        return 0;
    }
    //Gets the total sum of all prices
    Total = price1 + price2 + price3;
    
    
    cout << "Total to be paid: " << Total << " " << "PHP" << endl;
    cout << "Items:" << endl << Item1 << " " <<  price1 << " PHP" << endl << Item2 << " " << price2 << " PHP" << endl << Item3 << " " << price3 << " PHP" << endl; 
    cout << "Input proper amount to be paid: " << endl;
    cin >> pay;
    
    //Checks if amount input is sufficient
    if (pay >= Total) { 
        int Change = pay - Total;
       
       //Displays all Items bought their prices and the total amount to be paid, amount of payment given, and change
        cout << endl << "Item bought: " << endl << Item1 << " " <<  price1 << " PHP" << endl << Item2 << " " << price2 << " PHP" << endl << Item3 << " " << price3 << " PHP" << endl << "Total: " << Total << " PHP" << endl << "Change: " << Change << " PHP" << endl; 
   
    }
    else {
        cout << "Input amount insufficient try again";
    }
    
    return 0;
}
