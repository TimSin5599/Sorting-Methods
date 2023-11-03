#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& array)
{
    size_t length = array.size();
    for (int i = 0; i < length - 1; ++i)
    {
        int j = i+1;
        while (j > 0 && array[j - 1] > array[j])
        {
            std::swap(array[j-1], array[j]);
            --j;
        }
    }
}