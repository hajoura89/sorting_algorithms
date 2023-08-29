#include "sort.h"

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the Quicksort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Description: print the array after each
 * time you swap two elements
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme
 * @array: The array to order
 * @size: The size of the array
 * @higher: The starting index of the subset to order
 * @lower: The ending index of the subset to order
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, tmp = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			if (tmp != array[i])
				print_array(array, size);

			++i;
		}
	}

	tmp = array[i];
	array[i] = array[higher];
	array[higher] = tmp;

	if (tmp != array[i])
		print_array(array, size);

	return (i);
}
