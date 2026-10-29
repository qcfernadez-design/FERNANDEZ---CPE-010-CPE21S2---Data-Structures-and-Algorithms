#include <iostream>
#include <string.h>

class Student{
  private:
  std:: string studentName;
  int studentAge;

  public:
  Student (std:: string newName ="Cedric", int newAge = 200) {
    studentName = std:: move (newName);
    studentAge = newAge;
    std :: cout << "Constructor called." << std:: endl;
  };

  ~Student () {
    std:: cout << "deconstructor called" << std:: endl;
  }

  Student(const Student &copyStudent) {
    std:: cout << "copy constructor called" << std:: endl;
    studentName = copyStudent.studentName;
    studentAge = copyStudent.studentAge;
  }

  void printDetails () {
    std::cout << this ->studentName << " " << this -> studentAge << std:: endl;
  }

};

int main() {
  Student student1("Mike", 80);
  Student student2(student1);
  Student student3;
  student3 = student2;

  return 0;
}
