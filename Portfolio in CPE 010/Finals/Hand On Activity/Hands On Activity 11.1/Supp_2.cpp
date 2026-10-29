#include <iostream>
#include <chrono>

typedef unsigned long long BigInt;

long long totalCalls;

BigInt linearPower(BigInt base, int exp) { 
    totalCalls++; 
    if (exp == 0) return 1; 
    return base * linearPower(base, exp - 1); 
}

BigInt binaryPower(BigInt base, int exp) {
    totalCalls++;
    if (exp == 0) return 1;
    BigInt subResult = binaryPower(base, exp / 2);
    return (exp % 2 != 0) ? base * subResult * subResult : subResult * subResult;
}

int main() {
    for (int exponent : {1000, 3000, 6000, 9000}) {
        totalCalls = 0;
        auto startTime = std::chrono::steady_clock::now(); 
        linearPower(2, exponent);
        auto stopTime = std::chrono::steady_clock::now();
        
        auto linearDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime).count();
        std::cout << "rpower  n=" << exponent << " calls=" << totalCalls << " "
                  << linearDuration << " nanoseconds\n";
        totalCalls = 0;
        startTime = std::chrono::steady_clock::now(); 
        binaryPower(2, exponent);
        stopTime = std::chrono::steady_clock::now();
        auto binaryDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime).count();
        std::cout << "brpower n=" << exponent << " calls=" << totalCalls << " "
                  << binaryDuration << " nanoseconds\n";
    }

    return 0;
}