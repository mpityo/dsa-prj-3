#pragma once
#include <vector>

template <typename T>
int partition(std::vector<T>& v, int low, int high)
{
    // Select pivot to be the first element, this can cause worst-case performance for nearly-sorted or nearly-reverse-sorted data,
    // but since the data is random, we don't have to deal with that problem.

    T pivot = v[low];
    int start = low;
    int end = high;

    while(start < end)
    {
        while(v[start] <= pivot && start < high)
        {
            start++;
        }

        while(v[end] > pivot && end > low) 
        {
            end--;
        }

        if(start < end)
        {
            // swap
            T temp = v[start];
            v[start]  = v[end];
            v[end] = temp;
        }
    }

    // swap with the pivot
    T temp = v[low];
    v[low] = v[end];
    v[end] = temp;

    return end;
}

template <typename T>
void quickSortHelper(std::vector<T>& v, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(v, low, high);
        quickSortHelper(v, low, pivot - 1);
        quickSortHelper(v, pivot + 1, high);
    }
 
}

template <typename T>
void quickSort(std::vector<T>& v)
{
    quickSortHelper(v, 0, v.size() - 1);
}
