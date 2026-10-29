#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main() {

    //create qan array with unsorted list wit h100 maximum size
    int unsortedArr[maxSize];
    // use time  (0) as seed for random values
    srand(time(0));
    //populate the array with random values
    for (int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }
    //display the randomly generated array
    displayArr(unsortedArr);

//============= BUBBLE SORT CALL FUNCTION =================
    std::cout<<"\n bubble sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

//============= SELECTION SORT CALL FUNCTION =================
    std::cout<<"\n selection sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

//============= INSERTION SORT CALL FUNCTION =================
    std::cout<<"\n insertion sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<< '\n';
}