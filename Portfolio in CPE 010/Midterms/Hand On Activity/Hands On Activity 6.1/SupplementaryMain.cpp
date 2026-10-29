#include <iostream>
#include "searchingAlgo.h"

int main(){
    //====================FOR PROBLEM 1=======================================================
//     int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
//     int size = 10;
//     int key = 18;

//     // For Array search
//     int arrayComparisons = linearSearchAR(size, key, arr);
//     std::cout << "Array search" << '\n';
//     std::cout << "Comparisons needed: " << arrayComparisons << '\n';
//     // For Linked list
//     Node<int>* head = nullptr;
//     Node<int>* tail = nullptr;

//     for(int i = 0; i < size; i++){
//         Node<int>* newNode = new_node(arr[i]);
//         if(head == nullptr){
//             head = newNode;
//             tail = newNode;
//         }
//         else{
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     int listComparisons = linearSearchLL(head, key);
//     std::cout << "Linked list search" << '\n';
//     std::cout << "Comparisons needed: " << listComparisons << '\n';
//     deleteNodes(&head);
    
//     return 0;
// }
    //====================FOR PROBLEM 2=======================================================
//     int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
//     int size = 10;
//     int k = 18;

//     int arrayCount = linearSearchAR(size, k, arr);
//     std::cout << "Array" << std::endl;
//     std::cout << "The number of occurrences of " << k
//          << " is: " << arrayCount << std::endl;

//     return 0;
// }
    //====================FOR PROBLEM 3=======================================================
// int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

//     int size = 10;
//     int key = 8;
//     binarySearchArr(arr, size, key);

//     return 0;
// }
    //====================FOR PROBLEM 4=======================================================
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int dataFind = 8;

    binarySearchArr(data, 0, size - 1, dataFind);
    return 0;
}
