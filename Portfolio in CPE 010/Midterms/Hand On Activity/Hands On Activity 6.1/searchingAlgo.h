#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

//====================FOR PROBLEM 1=======================================================
//changed to int so it could actually return a value instead of none
// template <typename T>
// int linearSearchAR(int size, T dataFind, T array[]){

     //added compare variable so we can use the following to give the number of comparissons for both
     //linearSearchAR and LinearSearchLL
//     int i= 0;
//     int compare = 0; 

//     while(i < size){
//         compare++; 
//         if(dataFind == array[i]){
//             return compare; 
//         }
//         i++;
//     }
//     return compare; 
// }

//=========================FOR PROBLEM 2=================================
template <typename T>
int linearSearchAR(int size, T dataFind, T array[]){

    int i = 0;
    int count = 0;
    while(i < size){
        if(dataFind == array[i]){
            count++;
        }
        i++;
    }
    return count;
} 
//====================FOR PROBLEM 1===============================================
template <typename T>
int linearSearchLL(Node<T> *nodes, T dataFind){
    //repeat the loop until the current node is not NULL
    int compare = 0;
    while(nodes != nullptr){
        compare++;
        if(nodes->data == dataFind){
            return compare;
        }
        // move on to the next node
        nodes = nodes->next;

    }
    return compare;
}
//=========================FOR PROBLEM 3=================================
// template <typename T>
// void binarySearchArr(T data[], int arrSize, T dataFind){

//     int low = 0;
//     int high = arrSize - 1;
//     int middle;
//     int iteration = 1;

//     while(low <= high){
//         middle = (low + high) / 2;
//         std::cout << "Iteration " << iteration << std::endl;
//         std::cout << "Low: " << low << std::endl;
//         std::cout << "High: " << high << std::endl;
//         std::cout << "Middle: " << middle << std::endl;
//         std::cout << "Value at middle: " << data[middle] << std::endl;

//         if(dataFind == data[middle]){
//             std::cout << "The data was found!" << std::endl;
//             return;
//         }
//         else if(dataFind < data[middle]){
//             std::cout << "Key is smaller. Searching left." << std::endl;
//             high = middle - 1;
//         }
//         else{
//             std::cout << "Key is larger. Searching right." << std::endl;
//             low = middle + 1;
//         }

//         iteration++;
//         std::cout << std::endl;
//     }
//     std::cout << "The data was not found." << std::endl;
// }

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){

    //while loop or for loop
    int i= 0;

    while(i < size){
        if(dataFind == array[i]){
            std::cout<<"Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout<<"Searching is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    //repeat the loop until the current node is not NULL

    while(nodes != nullptr){

        //check if the item = current node data
        if(nodes->data == dataFind){
            std::cout << "The data: " << nodes->data << " was found successfully.\n";
            return;
        }
        // move on to the next node
        nodes = nodes->next;

    }
    //display unsuccessful
    std::cout << "Searching is unsuccessful.\n";
}
//=========================FOR PROBLEM 4=================================
template <typename T>
void binarySearchArr(T data[], int low, int high, T dataFind){

    if(low > high){
        std::cout << "The data was not found\n";
        return;
    }
    int middle = (low + high) / 2;

    if(dataFind == data[middle]){
        std::cout << "The data was found\n";
        return;
    }
    else if(dataFind < data[middle]){
        binarySearchArr(data, low, middle - 1, dataFind);
    }
    else{
        binarySearchArr(data, middle + 1, high, dataFind);
    }
}

// template <typename T>
// void binarySearchArr(T data[], int arrSize, T dataFind){
//     int low = 0, high = arrSize - 1, middle;
//     while(low <= high){
//         middle = (int)((low+high)/2);
//         if(dataFind == data[middle]){
//             std::cout<<"the data was found\n";
//             return;
//         }
//         else if( dataFind < data[middle]){
//             high = middle -1;
//         }
//         else{
//             low = middle+1;
//         }
//     }
//     std::cout<<"the data was not found\n";
// }

//middle function getter:

template <typename T>

Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    //continue until fast reaches the end or the last ode of the current search range

    while(fast != last && fast->next != last){

        //move slow one step
        slow = slow ->next;
        // move fast two steps
        fast = fast ->next->next;
    }

    return slow;
}

template <typename T>
void binarySeachLL(Node<T>* start, T dataFind){
    //step 1: set start to the head of the list and set last to null
    Node<T>* last = nullptr;

    while(start != last){
        //Middle element is calculated using the two pointers approach discussed above
        Node<T> *middle = getMiddle(start, last);

        //If the middle element is same as the key to be searched, we return it.
        if(middle->data == dataFind){
            std::cout<< "searching is Successful\n";
            return;
        }
        //element
        else if(middle->data > dataFind){
            last = middle;
        }
        //Else if middle element is less than the key to be searched, we have to search on the right
        //side of the singly linked list. So, we set start pointer to the next element
        else{
            start = middle->next;
        }
    }

    std::cout<<"Searching is unsucessful\n";
}
#endif