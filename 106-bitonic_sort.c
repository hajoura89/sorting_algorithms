#include "sort.h"

void swap_integers(int *a, int *b);
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
		char flow);
void _bitonic(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm
 * @array: The array to  sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_bitonic(array, size, 0, size, UP);
}

/**
 * swap_integers - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_bitonic - Sort a bitonic sequence inside an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of the sequence in array to sort
 * @seq: The size of the sequence to sort
 * @flow: The direction to sort in
 */
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
					(flow == DOWN && array[i] < array[i + jump]))
				swap_integers(array + i, array + i + jump);
		}
		merge_bitonic(array, size, start, jump, flow);
		merge_bitonic(array, size, start + jump, jump, flow);
	}
}

/**
 * _bitonic - Convert an array of integers into a bitonic sequence
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of a block of the building bitonic sequence
 * @seq: The size of a block of the building bitonic sequence
 * @flow: The direction to sort the bitonic sequence block in
 */
void _bitonic(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		_bitonic(array, size, start, cut, UP);
		_bitonic(array, size, start + cut, cut, DOWN);
		merge_bitonic(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}
