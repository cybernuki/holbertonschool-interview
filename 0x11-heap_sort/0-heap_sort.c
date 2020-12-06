#include "sort.h"

/**
 * heapify - perform the heapify algorithm on the array
 * @arr: the given array
 * @n: size of the arrray
 * @i: current position
 * @original_size: original size of the array to use in the print function
 */
void heapify(int *arr, int n, int i, size_t original_size)
{
	int tmp = 0;
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		print_array(arr, original_size);
		heapify(arr, n, largest, original_size);
	}
}

/**
 * heap_sort - performs a heap sort on the given array
 * @array: given data array
 * @size: size of the  array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp = 0;

	if (!array)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
