#include "sort.h"

/**
 * swap - Swaps two integer values
 * @a: First element
 * @b: Second element
 * Return: Nothing
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Corrects the position of the pivot in the array
 * @array: Pointer to the array
 * @low: Index of the start
 * @high: Index of the end
 * @size: Size of the array
 * Return: Index of the pivot after correction
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low - 1;
    size_t j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    swap(&array[i + 1], &array[high]);
    if (array[i + 1] != array[high])
        print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_recursion - Helper function to recursively sort subarrays
 * @array: Array of integers
 * @low: Index of the start
 * @high: Index of the end
 * @size: Size of the array
 * Return: Nothing
 */
void quick_sort_recursion(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot_index;

    if (low < high)
    {
        pivot_index = partition(array, low, high, size);

        if (pivot_index > 0)
            quick_sort_recursion(array, low, pivot_index - 1, size);
        if (pivot_index < high)
            quick_sort_recursion(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Performs the quick sort algorithm on an array of integers
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursion(array, 0, size - 1, size);
}
