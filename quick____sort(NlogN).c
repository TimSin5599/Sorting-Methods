int sorting_five_numbers_using_7_comparisons(std::vector<int> &massive, int start)
{
    std::vector<int> array = {massive[start], massive[start + 1], massive[start + 2], massive[start + 3], massive[start + 4]};

    if (array[0] < array[1])
    {
        std::swap(array[0], array[1]);
    }

    if (array[2] < array[3])
    {
        std::swap(array[2], array[3]);
    }

    if (array[0] > array[2])
    {
        std::swap(array[0], array[2]);
        std::swap(array[1], array[3]);
    }

    // [1] <= [0] <= [2], [3] <= [2], insert [5]
    // ------------------------------------------------------------------------------

    if (array[0] > array[4])
    {
        if (array[1] > array[4])
        {
            std::swap(array[1], array[4]);
        }
        std::swap(array[0], array[4]);
    }
    else if (array[2] < array[4])
    {
        std::swap(array[2], array[4]);
    }
    // [1] <= [0] <= [4] <= [2], [3] <= [2]

    if (array[3] < array[0])
    {
        if (array[3] < array[1])
        {
            // [3] < [1] <= [0] <= [4] <= [2]
            std::swap(array[3], array[1]);
        }
        // [1] < [3] <= [0] <= [4] <= [2]
        std::swap(array[3], array[0]);
        // [1] < [0] <= [3] <= [4] <= [2]
    }
    else
    {
        if (array[3] > array[4])
        {
            // [1] <= [0] <= [3] < [4] <= [2]
            std::swap(array[3], array[4]);
        }
        // [1] <= [0] <= [3] <= [4] <= [2]
    }
    return array[3];
}

void compare(std::vector<int> &array, const int size, const int peak)
{
    int top = peak;
    int left = 2 * peak + 1;
    int right = 2 * peak + 2;

    if (left < size && array[left] > array[top])
    {
        top = left;
    }

    if (right < size && array[right] > array[top])
    {
        top = right;
    }

    if (top != peak)
    {
        std::swap(array[peak], array[top]);
        compare(array, size, top);
    }
}

void heap_sort(std::vector<int> &array, const int start, const int end)
{

    for (int i = start + (end - start) / 2 - 1; i >= start; i--)
    {
        compare(array, end - start, i);
    }

    for (int i = end - 1; i >= start; i--)
    {
        std::swap(array[start], array[i]);

        compare(array, i, start);
    }
}

void quick_sort_NlogN(std::vector<int> &array, const int start, const int end)
{
    int left = start, right = end;

    if (end - start < 150)
    {
        heap_sort(array, start, end);
        return;
    }

    std::vector<int> mid_arr = {array[start], array[start + (end-start)/5], array[start + 2*(end-start)/5], array[start + 3*(end-start)/5], array[end - 1]};
    int middle = sorting_five_numbers_using_7_comparisons(mid_arr, 0);

    while (left <= right)
    {
        while (array[left] < middle)
        { ++left; }
        while (middle < array[right])
        { --right; }
        if (left <= right)
        {
            std::swap(array[left], array[right]);
            ++left;
            --right;
        }
    }

    quick_sort_NlogN(array, start, right);
    quick_sort_NlogN(array, left, end);
}