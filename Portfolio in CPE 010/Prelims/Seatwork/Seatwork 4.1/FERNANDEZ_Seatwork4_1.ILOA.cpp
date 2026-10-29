#include <iostream>
#include <stack>

int main(){
    std::stack<int> stack1;
    std::cout<<"Testing the stack STL"<<std::endl;
    //isEmpty
    std::cout<<"Is the stack empty? " << stack1.empty()<<std::endl;
    //push
    stack1.push(10);
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    stack1.push(9);
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    stack1.push(8);
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    stack1.push(7);
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    //pop
    stack1.pop();
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    //isEmpty
    std::cout<<"Is the stack empty? " << stack1.empty()<<std::endl;
    
    //size
    std::cout<< "the size of the stack is: " <<stack1.size()<< std::endl;
    //emplace
    stack1.emplace(11);
    std::cout<<"the top of the stack is " << stack1.top() <<std::endl;
    
    std::stack<int> stack2;
    stack2.push(12);
    stack2.push(13);
    stack2.push(14);
    //swap
    stack1.swap(stack2);
    std::cout<<"the top of the stack1 is " << stack1.top() <<std::endl;
    std::cout<<"the top of the stack2 is " << stack2.top() <<std::endl;
    
    return 0;
}