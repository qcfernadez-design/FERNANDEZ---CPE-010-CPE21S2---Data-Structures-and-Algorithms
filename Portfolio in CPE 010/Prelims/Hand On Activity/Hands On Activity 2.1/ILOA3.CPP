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
        std::cout << "Constructor called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor called." << std::endl;
    }

    Student(const Student &copyStudent) {
        std::cout << "Copy constructor called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    // Copy Assignment Operator needed for studentList
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

    Student studentList[j] = {};
    std::string nameList[j] = {"Angelo", "Berny", "Chris", "Dave", "Ester"};
    int ageList[j] = {10, 20, 30, 40, 50};

    // Loop A
    for (int i = 0; i < j; i++) {
        Student *ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr; 
        delete ptr; 
        // prevent risk of memory leak by freeing dynamically allocated heap memory
    }

    //  Display details Loop B
    for (int i = 0; i < j; i++) {
        studentList[i].printDetails();
    }

    return 0;
}