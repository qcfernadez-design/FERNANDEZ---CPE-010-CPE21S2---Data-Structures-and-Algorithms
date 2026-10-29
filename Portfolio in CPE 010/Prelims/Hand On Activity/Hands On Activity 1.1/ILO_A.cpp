//Fernandez, Cedric S. CpE21S2
#include <iostream>

//Section where the prototype functions are stored
void twoNum(int num1, int num2);
bool greaterVal(int VarA, int VarB);
bool trueOrfalse(bool x, bool y);

//The section where the compiler start and calls the prototype functions
int main () {
    twoNum(5, 10);
    greaterVal(5, 10);
    trueOrfalse(true, false);

    std::cout << std::boolalpha;

    std::cout << "Variable A is greater than Variable B: " << greaterVal << std::endl;
    return 0; 
}

//Section where the prototype functions are being executed and ran before being displayed and ending the program
void twoNum(int num1, int num2) {
    int sum = num1 + num2;
    std::cout << "The sum of the two numbers is: " << sum << std::endl;
}

bool greaterVal(int VarA, int VarB) {
    if (VarA > VarB) {
        return true;
    }
    else { 
        return false;
    }
}

bool trueOrfalse(bool x, bool y) {

    std::cout << std::boolalpha;
    std::cout << "AND result: " << (x && y) << std::endl;
    std::cout << "OR result: " << (x || y) << std::endl;
    std::cout << "NOT x result: " << (!x) << std::endl;

    return true; 
}