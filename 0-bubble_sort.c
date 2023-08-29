#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Return: Nothing!
 */
void bubble_sort(int *array, size_t size)
{
	int i = 0, tmp = 0, len = 0, swap = 1;

	if (!array || size < 2)
		return;

	len = size - 1;

	for (; i < len; ++i)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			swap = 1;
			print_array(array, size);
		}

		if (swap == 1 && i == len - 1)
			i = -1, swap = 0, --len;
	}
}
