//Cedric S Fernandez CpE21S2
#include <iostream>
//Enables us to use adavance math like square root and power
#include <cmath>

//decleration of prototype function we used void here because we plan to also make each said function to output text 
//along with the answer to their final computation or output
void swapVar ();
void kelvinTofahrenheit ();
void distanceCalculator();

int main () { 

int choice;

//Displays the menu and ask for users choice on what option they want
std:: cout<< " Welcome! please choose one of the following" << std::endl;
std:: cout<< "1.) Swap values between 2 variables" << std::endl;
std:: cout<< "2.) Convert kelvin to Fahrenheit" << std::endl;
std:: cout<< "3.) Calculate distance between 2 points" << std::endl;
std:: cout<< "Please input one of the following from the menu (1-3): ";
std::cin >> choice;

//Is the portion that makes the menu section work with the use of switch cases and prototype functions
switch (choice) {
    case 1:
    swapVar();
    break;

    case 2:
    kelvinTofahrenheit();
    break;

    case 3:
    distanceCalculator();
    break;

    default:
    std::cout << "Invalid inpute please choose from 1-3: ";
    break;
    }
    return 0;
}

//Section where the prototype function are stored and executed when called

//Variable swapper
void swapVar() {
int num1, num2;
std::cout << "Enter first number (Num1): ";
std::cin >> num1;
std::cout << "Enter second number (Num2): ";
std::cin >> num2;

std::cout << "Before Swap Var A = " << num1 << ", Var B = " << num2 << std::endl;
std::swap(num1, num2);
std::cout << "After Swap Var A = " << num1 << ", Var B = " << num2 << std::endl;
}

//Kelvin to fahrenheit converter
void kelvinTofahrenheit() {
double kelvin, fahrenheit;
std::cout << "Enter temperature in Kelvin: ";
std::cin >> kelvin;

//Just used the formula for Kelvin to fahrenheit online: F = (K - 273.15) * 9/5 + 32
fahrenheit = (kelvin - 273.15) * 9.0 / 5.0 + 32.0;

std::cout << kelvin << "K is equal to " << fahrenheit << " F ";
}

// Distance calculator
void distanceCalculator() {
double x1, y1, x2, y2, distance;
std::cout << "Enter Coordinates for Point 1 (x1 y1): ";
std::cin >> x1 >> y1;
std::cout << "Enter Coordinates for Point 2 (x2 y2): ";
std::cin >> x2 >> y2;

// Just used Euclidean Distance Formula here from online which is sqrt((x2-x1)^2 + (y2-y1)^2)
distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
std::cout << "The distance between the two points is: " << distance << std::endl;
}