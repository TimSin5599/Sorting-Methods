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

void heap_sort(std::vector<int> &array, const int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        compare(array, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(array[0], array[i]);

        compare(array, i, 0);
    }
}