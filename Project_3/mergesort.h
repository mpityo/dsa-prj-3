#pragma once
#include <vector>
#include <iostream>
#include <cmath>

template <typename T>
void Merge (std::vector<T>& arr, int start, int middle, int end, std::function<bool(const T&, const T&, string comparison, bool equal)> comparator) {
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
        if (comparator(left[i],right[j],"less",true)) {
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
void mergeSortHelper (std::vector<T>& arr, int start, int end, std::function<bool(const T&, const T&, string comparison, bool equal)> comparator) {
    if (start < end) {
        int middle = floor((start + end) / 2);
        mergeSortHelper(arr,start,middle,comparator);
        mergeSortHelper(arr,middle + 1,end,comparator);
        Merge(arr, start, middle, end,comparator);
    }
}
template <typename T>
void mergeSort (std::vector<T>& v, std::function<bool(const T&, const T&, string comparison, bool equal)> comparator) {
    mergeSortHelper(v,0,v.size()-1,comparator);
}