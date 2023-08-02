#pragma once
#include <vector>

int partition(std::vector<float>& v, int low, int high)
{
    // Select pivot to be the firt element, this can cause worst-case performance for nearly-sorted or nearly-reverse-sorted data, 
    // but since the data is random, we don't have to deal with that problem.

    int pivot = v[low];
    int start = low;
    int end = high;

    while(start < end)
    {
        while(v[start]  <= pivot && start < high)
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
            float temp = v[start];
            v[start]  = v[end];
            v[end] = temp;
        }
    }

    // swap with the pivot
    float temp = v[low];
    v[low]  = v[end];
    v[end] = temp;

    return end;
}

void quickSortHelper(std::vector<float>& v, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(v, low, high);
        quickSortHelper(v, low, pivot - 1);
        quickSortHelper(v, pivot + 1, high);
    }
 
}

void quickSort(std::vector<float>& v)
{
    quickSortHelper(v, 0, v.size() - 1);
}
