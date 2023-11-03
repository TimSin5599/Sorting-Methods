void insertion_sort_with_bin_search(std::vector<int>& array)
{
    size_t length = array.size();
    for (int i = 0; i < length - 1; ++i)
    {
        int j = i+1;
        int start = 0, end = i, elem = array[j], middle = (start + end) / 2;

        {//bin search  array = sorted | unsorted
            while (elem != array[middle])
            {
                middle = (start + end) / 2;
                if (end <= start) {middle = elem > array[start] ? start + 1 : start; break;}
                if (elem > array[middle]) {start = middle + 1;}
                else {end = middle - 1;}
            }
        }

        while (j > middle)
        {
            std::swap(array[j-1], array[j]);
            --j;
        }
    }
}