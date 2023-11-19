#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the Counting Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *new_array, max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }

    count_array = malloc(sizeof(int) * (max + 1));
    new_array = malloc(sizeof(int) * size);

    if (!count_array || !new_array)
    {
        free(count_array);
        free(new_array);
        return;
    }

    for (i = 0; i <= (size_t)max; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    for (i = 1; i <= (size_t)max; i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max + 1);

    for (i = size - 1; i < size; i--)
    {
        new_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = new_array[i];

    free(count_array);
    free(new_array);
}
