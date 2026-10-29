#include <iostream>
#include <string>
#include "supplementary_stacklist.h"

int main() {
    std::string newString;
    bool isBalanced = true;

    std::cout << "Enter a String: ";
    std::cin >> newString;

    for (size_t j = 0; j < newString.length(); j++) {
        char charac = newString[j];

        if (charac != '(' && charac != '[' && charac != '{' && 
            charac != ')' && charac != ']' && charac != '}') {
            continue;
        }

        if (charac == '(' || charac == '[' || charac == '{') {
            push<char>(charac); 
        }


        if (charac == ')' || charac == ']' || charac == '}') {
            if (isEmpty<char>()) {
                std::cout << "The Stack is Empty!"<< std::endl;
                isBalanced = false;
                break;
            }

            char poppedIndex = pop<char>();
            if (!isMatching<char>(poppedIndex, charac)) {
                isBalanced = false;
                break;
            }
        }
    }

    if (isBalanced && isEmpty<char>()) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}