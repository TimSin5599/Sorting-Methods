#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &arr, const int start, const int end)
{
    if (end - start < 2) {return;}

    merge_sort(arr, start, start + (end-start) / 2);
    merge_sort(arr, start + (end-start) / 2, end);

    std::vector<int> res;
    int start_one = start, start_two = start + (end-start) / 2, middle = start_two;

    while (res.size() < (end - start))
    {
        if (((arr[start_one] <= arr[start_two]) || (start_two >= end)) && (start_one < middle))
        {
            res.push_back(arr[start_one]);
            ++start_one;
        }
        else
        {
            res.push_back(arr[start_two]);
            ++start_two;
        }
    }

    for (int i = start; i < end; ++i)
    {
        arr[i] = res[i - start];
    }
}