#include <iostream>

//global declarations
#define maxCap 10
int stackArr[maxCap];
int top = -1, newData;
//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayStack();

int main(){
    //main driver
    int choice;
    while(true){
        std::cout<<"============================================================="<<std::endl;
        std::cout<<"Stack Operations"<<std::endl;
        std::cout<<"1. PUSH 2. POP 3. TOP 4. isEmpty 5. isFull 6. Display Stack"<<std::endl;
        std::cout<<"============================================================="<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << "is stack empty? " <<isEmpty()<<std::endl;
            break;
            case 5: std::cout<<"is the stack full? "<<isFull()<<std::endl;
            break;
            case 6: displayStack();
            break;
            default: std::cout<<"Invalid Choice"<<std::endl;
            break;
        }
    }
}
// function declarations
bool isEmpty(){
    if(top == -1) return true;
    return false;
}
bool isFull(){
    if(top == maxCap - 1) return true;
    return false;
}
void push(){
    if(isFull()){
        std::cout<<"Stack Overflow"<<std::endl;
        return;
    }
    std::cout<<"Enter a new value: "<<std::endl;
    std::cin >> newData;
    stackArr[++top] = newData;
}
void pop(){
    if(isEmpty()){
        std::cout<<"Stack Underflow"<<std::endl;
    }

    //display the value that we are going to pop
    std::cout<<"Popping: "<<stackArr[top]<<std::endl;
    //decrement the top value from the stack
    top--;
}
void Top(){
    if(isEmpty()){
        std::cout<<"The Stack is Empty"<<std::endl;
        return;
    }
    //check the top value
    std::cout<<"Top element: " << stackArr[top]<<std::endl;
}
void displayStack(){
    if(isEmpty()){
        std::cout<<"The Stack is Empty"<<std::endl;
        return;
    }
    //display stack
    std::cout<<"Stack: ";
    for (int j = top; j >= 0; j--){
        std::cout<< stackArr[j]<<" ";
    }
    std::cout<<std::endl;
}