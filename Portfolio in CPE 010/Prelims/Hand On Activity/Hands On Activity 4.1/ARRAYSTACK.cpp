#include <iostream>
#include <string>

//Global declerations
#define MAX_CAP 100
void push(char val);
char pop();
char top();
bool isEmpty();
bool isMatchingPair(char open, char close);
char stackArr[MAX_CAP];
//prototype functions
int topIndex = -1;

//main drive 
int main() {
    std::string newString;
    bool isBalanced = true;
    std::cout << "Enter a String: ";
    std::cin >> newString;

    for (size_t j = 0; j < newString.length(); j++) {
        char charac = newString[j];

        if(charac != '(' && charac != '[' && charac != '{' && 
           charac != ')' && charac != ']' && charac != '}'){
               continue;
        }


        if (charac == '(' || charac == '[' || charac == '{') {
            push(charac);
        }

        if (charac == ')' || charac == ']' || charac == '}') {
            if(isEmpty()){
                std::cout<<"The Stack is Empty!"<<std::endl;
                isBalanced = false;
            }
            char poppedIndex = pop();
            bool match = isMatchingPair(poppedIndex, charac);
            if(match == 1){
                std::cout<< poppedIndex<<" and "<<charac<<" are matching"<<std::endl;
            }else{
                std::cout<<"ERROR: "<<poppedIndex<< " and "<<charac<<" are NOT matching"<<std::endl;
            }
            if (!isMatchingPair(poppedIndex, charac)) {
                isBalanced = false; 
                break;              
            }
        }

    }
    if (isBalanced && isEmpty()) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}

void push(char val) {
        if (topIndex >= MAX_CAP - 1) {
            std::cout << "Array Stack Overflow\n";
            return;
        }
        stackArr[++topIndex] = val;
    }

char pop() {
        if (isEmpty()) {
            std::cout << "Array Stack Underflow\n";
            return '\0';
        }
        return stackArr[topIndex--];
    }

char top() {
        if (isEmpty()) return '\0';
        return stackArr[topIndex];
    }

bool isEmpty() {
        return topIndex == -1;
    }

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}