#include <iostream>
#include <cstdlib> // For generating random integers
#include <ctime>   // For time-based seeding
#include <algorithm> // For std::copy
#include "SortingAlgo.h"

const int max_size = 100;

int main() {

    std::cout<<"100 item integer (unsorted): "<<std::endl;
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size ; i++){
        dataset[i] = rand();
    std::cout<< dataset[i] <<" ";
}
std::cout<<std::endl;

    int shellArray[max_size];
    int mergeArray[max_size];
    int quickArray[max_size];

std::copy(dataset, dataset + max_size, shellArray); 
std::copy(dataset, dataset + max_size, mergeArray); 
std::copy(dataset, dataset + max_size, quickArray);

//==================SHELL SORT=================
    shellSort(shellArray, max_size);
    std::cout << "\nShell Sort:\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << shellArray[i] << " ";
    }
    std::cout << " " << std::endl;

//==================MERGE SORT==================
    mergeSort(mergeArray, 0, max_size - 1);
    std::cout << "\nMerge Sort:\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << mergeArray[i] << " ";
    }
    std::cout << " " << std::endl;

//==================QUICK SORT==================
    quickSort(quickArray, 0, max_size - 1);
    std::cout << "\nQuick Sort:\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << quickArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}