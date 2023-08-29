#include "sort.h"

void swap_integers(int *a, int *b);
void max_heap(int *array, size_t size, size_t base, size_t root);

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_integers(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
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
 * max_heap - Turn a binary tree into a complete binary heap
 * @array: An array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 */
void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_integers(array + root, array + large);
		print_array(array, size);
		max_heap(array, size, base, large);
	}
}
