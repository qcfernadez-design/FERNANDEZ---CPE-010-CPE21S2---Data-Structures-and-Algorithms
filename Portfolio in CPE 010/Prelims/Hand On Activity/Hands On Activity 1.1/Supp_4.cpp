// Cedric S Fernandez CpE21S2
#include <iostream> 
// Needed for squareroot and power in solving 
#include <cmath>    


class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    //We added this section so that the program can start accepting side length so we can get the parameter and area of a triangle
    double sideA, sideB, sideC; 

public:
    // Constructor declaration
    Triangle(double A, double B, double C, double sA, double sB, double sC);
    
    void setAngles(double A, double B, double C);
    const bool validateTriangle();

    //introduced 3 new prototype functions so that we won't get an error when calling for them
    double calculateArea();
    double calculatePerimeter();
    std::string determineType(); 
};

int main() {
    // Create a triangle with angles (40, 30, 110) and sides (7.0, 5.5, 10.3)
    Triangle set1(40, 30, 110, 7.0, 5.5, 10.3);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Perimeter: " << set1.calculatePerimeter() << " units\n";
        std::cout << "Area: " << set1.calculateArea() << " sq. units\n";
        std::cout << "Triangle Classification: " << set1.determineType() << "\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}

// Fixed Constructor: Now saves BOTH angles AND sides to our private variables
Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    //The added section where we'll store the side length
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

//Perimeter calculator
double Triangle::calculatePerimeter() {
    return sideA + sideB + sideC;
}

// section that finds the area using Heron's Formula found online
double Triangle::calculateArea() {
    double s = calculatePerimeter() / 2.0;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

//Triangle type identifier
std::string Triangle::determineType() {
    if (!validateTriangle()) {
        return "Invalid Triangle";
    }
    
    // Checks if any single angle is obtuse (greater than 90)
    if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled";
    }
    // Checks if all angles are acute (less than 90)
    else if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute-angled";
    }
    // Any other case (like having exactly a 90 degree angle)
    else {
        return "Others (Right-angled)";
    }
}