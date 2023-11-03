void quick_sort(std::vector<int> &array, const int start, const int end)
{
    int left = start, right = end;

    if (end - start <= 0) {return;}

    int middle = array[(start + end) / 2];

    while (left <= right)
    {
        while (array[left] < middle) {++left;}
        while (middle < array[right]) {--right;}
        if (left <= right)
        {
            std::swap(array[left], array[right]);
            ++left; --right;
        }
    }

    quick_sort(array, start, right);
    quick_sort(array, left, end);
}