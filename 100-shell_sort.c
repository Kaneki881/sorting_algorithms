#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the Shell Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
			}
		}
		print_array(array, size);
	}
}
