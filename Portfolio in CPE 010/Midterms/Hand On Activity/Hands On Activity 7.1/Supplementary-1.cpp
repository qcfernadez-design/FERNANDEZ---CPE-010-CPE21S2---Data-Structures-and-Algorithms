#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"
#include "searchingAlgo.h"
#include <string>

const int maxSize = 100;
int votes[6] = {};
std::string candidateNames[6] = {"", "Bo Dalton Capistrano", "Cornelius Raymon Agustin", "Deja Jayla Banaga", "Lalla Brielle Yabut", "Franklin Relano Castro"};
void displayArr(int arr[]);

int main() {

    //create qan array with unsorted list wit h100 maximum size
    int unsortedArr[maxSize];
    // use time  (0) as seed for random values
    srand(time(0));
    //Generates the random vote 1-5
    for (int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()% 5 + 1;
    }
    //display the randomly generated array
    std::cout << "unsorted array\n";
    displayArr(unsortedArr);

    //Reused code for sorting
    std::cout<<"\n insertion sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    //vote counter for each candidate
    for (int candidate = 1; candidate <= 5; candidate++) {
        votes[candidate] = linearSearchAR(maxSize, candidate, unsortedArr);
    }
    // Display the number of votes for each candidate
    std::cout << "\nVote count:\n";

    for (int candidate = 1; candidate <= 5; candidate++) {
        std::cout << "Candidate " << candidate << " - " << candidateNames[candidate] << ": " << votes[candidate] << " votes\n";
    }

    // Assume Candidate 1 is the winner initially
    int winner = 1;

    // Compare each candidate with the current winner
    for (int candidate = 2; candidate <= 5; candidate++) {
        if (votes[candidate] > votes[winner]) {
            winner = candidate;
        }
    }

    // Display the winner
    std::cout << "\nWinner: Candidate " << winner
              << " - " << candidateNames[winner]
              << " with " << votes[winner]
              << " votes!\n";

    return 0;
}

void displayArr(int arr[]) {

    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}