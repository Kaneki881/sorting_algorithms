#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merge two subarrays into a sorted array
 * @array: Original array
 * @left_size: Size of the left subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, size_t left_size, size_t right_size)
{
	size_t merged_size = left_size + right_size;
	int *merged_array = malloc(merged_size * sizeof(int));

	if (merged_array == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	size_t left_index = 0, right_index = 0, merged_index = 0;

	while (left_index < left_size && right_index < right_size)
	{
		if (array[left_index] <= array[left_size + right_index])
			merged_array[merged_index++] = array[left_index++];
		else
			merged_array[merged_index++] = array[left_size + right_index++];
	}

	while (left_index < left_size)
		merged_array[merged_index++] = array[left_index++];

	while (right_index < right_size)
		merged_array[merged_index++] = array[left_size + right_index++];

	for (size_t i = 0; i < merged_size; i++)
		array[i] = merged_array[i];

	free(merged_array);
}

/**
 * merge_sort - Recursive function to perform merge sort on an array
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);

		merge(array, mid, size - mid);
	}
}

/**
 * print_array - Print elements of an array
 * @array: Array to be printed
 * @size: Size of the array
 */
void print_array(int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	print_array(arr, size);

	merge_sort(arr, size);

	printf("Sorted array: ");
	print_array(arr, size);

	return (0);
}
