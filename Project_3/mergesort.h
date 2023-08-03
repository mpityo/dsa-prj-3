#pragma once
#include <vector>
#include <iostream>
#include <cmath>

std::vector<float> TEST = {0,9,3,54,1,3,578,43,123434,245,342,453656,67,5431,3412,1,234,2345,56,41,14,234,24,2345,2315213,12634,436,4567456,58,9879};

template <typename T>
void Merge (std::vector<T>& arr, int start, int middle, int end) {
    int leftHalf = middle - start + 1;
    int rightHalf = end - middle;

    std::vector<T> left (leftHalf);
    std::vector<T> right (rightHalf);

    for (int i = 0; i < leftHalf; i ++)
        left[i] = arr[start + i];
    for (int j = 0; j < rightHalf; j++)
        right[j] = arr[middle + 1 + j];

    // pointers to keep track of where we're at in the sub arrays/main array
    int i = 0;
    int j = 0;
    int k = start;

    // copy both arrays
    while (i < leftHalf && j < rightHalf) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // if the left array still has values
    while (i < leftHalf) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // if the right array still has values
    while (j < rightHalf) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSortHelper (std::vector<T>& arr, int start, int end) {
    if (start < end) {
        int middle = floor((start + end) / 2);
        mergeSortHelper(arr,start,middle);
        mergeSortHelper(arr,middle + 1,end);
        Merge(arr, start, middle, end);
    }
}
template <typename T>
void mergeSort (std::vector<T>& v) {
    mergeSortHelper(v,0,v.size()-1);
}