#include "sort.h"

/**
 * heapify - performe a heapify on the array
 * @arr: the given array
 * @size: size of the array
 * @i: current position
 * @size: size
 */
void heapify(int *arr, int size, int i)
{
	int largest = i, tmp = 0;
	int left = 2 * i + 1;
	int right = left + 1;

	if (left < size && arr[largest] < arr[left])
		largest = left;

	if (right < size && arr[largest] < arr[right])
		largest = right;

	if (largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		heapify(arr, size, largest);
	}
}

/**
 * heap_sort - sorts an array of numbers
 * @array: the given data's array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp = 0;

	if (!array)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
