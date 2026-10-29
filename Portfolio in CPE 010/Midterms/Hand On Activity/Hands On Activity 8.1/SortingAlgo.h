#ifndef SORTINGALGO_H
#define SORTINGALGO_H

//=============SHELL SORT===================
template <typename T>
void shellSort(T array[], int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            T temp = array[i];
            int j = i;
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }
    }
}

//============MERGE SORT=====================
template <typename T>
void merge(T Arr[], int left, int middle, int right) {

    int N1 = middle - left + 1;
    int N2 = right - middle;

    T* Left = new T[N1];
    T* Right = new T[N2];

    for (int i = 0; i < N1; i++) {
        Left[i] = Arr[left + i];
    }
    for (int j = 0; j < N2; j++) {
        Right[j] = Arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < N1 && j < N2) {

        if (Left[i] <= Right[j]) {
            Arr[k] = Left[i];
            i++;
        }
        else {
            Arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < N1) {
        Arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < N2) {
        Arr[k] = Right[j];
        j++;
        k++;
    }
    delete[] Left;
    delete[] Right;
}

template <typename T>
void mergeSort(T array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

//================QUICK SORT===================
template <typename T>
int partition(T array[], int low, int high) {
    T pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    T temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

template <typename T>
void quickSort(T array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

#endif