#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 * @array: The array
 * @size: lenght of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, inner;
	int insertvalue;

	if (array == NULL || size < 2)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			insertvalue = array[i];
			inner = i;

			while (inner > interval - 1 && array[inner - interval] >= insertvalue)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}

			array[inner] = insertvalue;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
