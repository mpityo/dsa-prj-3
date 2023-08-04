#pragma once
#include <vector>

template <typename T>
int partition(std::vector<T>& v, int low, int high, std::function<bool(const T&, const T&, std::string comparison, bool equal)> comparator)
{
    // Select pivot to be the first element, this can cause worst-case performance for nearly-sorted or nearly-reverse-sorted data,
    // but since the data is random, we don't have to deal with that problem.

    T pivot = v[low];
    int start = low;
    int end = high;

    while(start < end)
    {
        // v[start] <= pivot
        while(comparator(v[start],pivot,"less",true) && start < high)
        {
            start++;
        }

        while(comparator(v[end],pivot,"greater",false) && end > low)
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
void quickSortHelper(std::vector<T>& v, int low, int high, std::function<bool(const T&, const T&, std::string comparison, bool equal)> comparator)
{
    if(low < high)
    {
        int pivot = partition(v, low, high, comparator);
        quickSortHelper(v, low, pivot - 1, comparator);
        quickSortHelper(v, pivot + 1, high, comparator);
    }
 
}

template <typename T>
void quickSort(std::vector<T>& v, std::function<bool(const T&, const T&, std::string comparison, bool equal)> comparator)
{
    quickSortHelper(v, 0, v.size() - 1, comparator);
}
