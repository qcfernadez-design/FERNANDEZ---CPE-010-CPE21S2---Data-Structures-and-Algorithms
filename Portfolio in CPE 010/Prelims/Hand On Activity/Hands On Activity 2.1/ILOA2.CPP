#include <iostream>
#include <string>
#include <utility>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    Student(std::string newName = "Cedric", int newAge = 200) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    // Copy assignment operator needed for array element
    Student& operator=(const Student &other) {
        if (this != &other) {
            studentName = other.studentName;
            studentAge = other.studentAge;
        }
        return *this;
    }

    void printDetails() const {
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }
};

int main() {
    const size_t j = 5;

    //calls the constructor 5 times
    Student studentList[j] = {};
    std::string nameList[j] = {"Angelo", "Berny", "Chris", "Dave", "Ester"};
    int ageList[j] = {10, 20, 30, 40, 50};

    //displayS student details
    for (size_t i = 0; i < j; i++) {
        studentList[i] = Student(nameList[i], ageList[i]);
        studentList[i].printDetails();
    }

    return 0; 
}