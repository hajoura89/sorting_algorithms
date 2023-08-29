#include "sort.h"

int _max(int *array, int size);

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Description: Prints the counting array
 */
void counting_sort(int *array, size_t size)
{
	int *count, max, i, *sort;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = _max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];

	free(sort);
	free(count);
}


/**
 * _max - The maximum value of an array of integers
 * @array: The array
 * @size: The size of the array
 * Return: The maximum
 */
int _max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

