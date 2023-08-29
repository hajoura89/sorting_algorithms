#include "sort.h"

void _subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sortrecursive(int *subarr, int *buff, size_t front, size_t back);

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sortrecursive(array, buff, 0, size);

	free(buff);
}

/**
 * _subarray - Sort a subarray of integers
 * @subarr: Subarray to sort
 * @buff: Buffer to store the sorted subarray
 * @front: The front index of the array
 * @mid: The middle index of the array
 * @back: The back index of the array
 */
void _subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sortrecursive - Implement the merge sort algorithm through recursion
 * @subarr: Subarray of an array of integers to sort
 * @buff: A buffer to store the sorted result
 * @front: The front index of the subarray
 * @back: The back index of the subarray
 */
void merge_sortrecursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sortrecursive(subarr, buff, front, mid);
		merge_sortrecursive(subarr, buff, mid, back);
		_subarray(subarr, buff, front, mid, back);
	}
}
