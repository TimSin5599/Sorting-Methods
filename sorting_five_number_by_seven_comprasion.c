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
//// [1] < [0] <= [3] <= [4] <= [2]
//    std::swap(array[0], array[1]);
//// [0] < [1] <= [3] <= [4] <= [2]
//    std::swap(array[3], array[2]);
//// [0] < [1] <= [2] <= [4] <= [3]
//    std::swap(array[3], array[4]);
//// [0] < [1] <= [2] <= [3] <= [4]
//    return array[2];
}