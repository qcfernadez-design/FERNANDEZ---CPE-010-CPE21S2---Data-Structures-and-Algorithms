#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main () {

  //create an object
  std::queue<char> myQ;

  //use the push operation
  myQ.push('C');
  myQ.push('E');
  myQ.push('D');
  myQ.push('R');
  myQ.push('I');
  myQ.push('C');
  std::cout<< "current FRONT is " << myQ.front()<<std::endl;
  std::cout<< "current BACK is " << myQ.back()<<std::endl;

  //use thge  dequeue operation
  myQ.pop();
  display(myQ);
  myQ.pop();
  display(myQ);
  myQ.pop();

  //check the queue if it is empty 
  std::cout<<"is the queue empty?" <<std::endl;

  return 0;
}

//note only use the member function of the queue STL
void display(std::queue<char> copyQ) {

  //create copy of the queue
  std::queue<char> temp = copyQ;

  //loop until empty
  while(!temp.empty()){
    //display the front
    std::cout<<" " << temp.front() << " ";
    //dequeue the fron
    temp.pop();
  }
  //add a new line 
  std::cout << std::endl;
}