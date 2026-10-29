#include <iostream>
#include <vector>
#include <chrono>

bool isUnique(const std::vector<int>& arr, long long& totalCompares) {
    int size = arr.size();
    for (int idx1 = 0; idx1 < size; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < size; idx2++) { 
            totalCompares++; 
            if (arr[idx1] == arr[idx2]) {
                return false; 
            }
        }
    }
    return true;
}

int main() {

    for (int sampleSize : {500, 1000, 2000, 4000}) {
        std::vector<int> numbers(sampleSize);
        for (int k = 0; k < sampleSize; k++) {
            numbers[k] = k; 
        }

        long long comparisonCount = 0;
        auto startTime = std::chrono::steady_clock::now();
        isUnique(numbers, comparisonCount);
        auto stopTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();

        std::cout << sampleSize << " | comparisons=" << comparisonCount << " | " << duration <<  " (microseconds)\n";
    }
    return 0;
}