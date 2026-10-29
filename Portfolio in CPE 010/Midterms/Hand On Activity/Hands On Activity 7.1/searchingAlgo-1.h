#include <iostream>
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

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
#endif