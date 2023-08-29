#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 1, tmp = 0, min = 0, len = size - 1;

	if (size < 2)
		return;

	while (i < len)
	{
		if (j == size)
		{
			if (i != min)
			{
				tmp = array[i];
				array[i] = array[min];
				array[min] = tmp;
				print_array(array, size);
			}

			++i;
			min = i;
			j = i + 1;
			continue;
		}

		if (array[min] > array[j])
			min = j;

		++j;
	}
}
