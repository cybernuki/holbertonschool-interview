#include "sort.h"

/**
 * sort - Sort subarrays
 * @arr: the given array
 * @l: left pointer
 * @r: right pointer
 * @start: start index
 * @mid: middle index
 * @end: end index
 */
void sort(int *arr, int *l, int *r, int start, int mid, int end)
{
	int left_iter, right_iter, array_iter;
	int left_size = mid - start + 1;
	int right_size = end - mid;

	left_iter = right_iter = 0;
	array_iter = start;

	while (left_iter < left_size && right_iter < right_size)
	{
		if (l[left_iter] < r[right_iter])
		{
			arr[array_iter] = l[left_iter];
			left_iter++;
		}
		else
		{
			arr[array_iter] = r[right_iter];
			right_iter++;
		}
		array_iter++;
	}

	while (left_iter < left_size)
	{
		arr[array_iter] = l[left_iter];
		left_iter++;
		array_iter++;
	}

	while (right_iter < right_size)
	{
		arr[array_iter] = r[right_iter];
		right_iter++;
		array_iter++;
	}
}

/**
 * conquer - Merge subarrays
 * @start: start index
 * @array: array
 * @mid: middle index
 * @end: last index
 */
void conquer(int *array, int start, int mid, int end)
{
	int left_iter, right_iter;
	int left_size = mid - start + 1;
	int right_size = end - mid;

#pragma GCC diagnostic ignored "-Wvla"
	int left[left_size];
	int right[right_size];

	for (left_iter = 0; left_iter < left_size; left_iter++)
		left[left_iter] = array[start + left_iter];
	for (right_iter = 0; right_iter < right_size; right_iter++)
		right[right_iter] = array[mid + right_iter + 1];

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	sort(array, left, right, start, mid, end);

	printf("[Done]: ");
	print_array(&array[start], left_size + right_size);
}

/**
 * divide - divide the array 
 * @array: array
 * @start: start index
 * @end: end index
 */
void divide(int *array, int start, int end)
{
	int mid = (start + end - 1) / 2;

	if (start >= end)
		return;

	divide(array, start, mid);
	divide(array, mid + 1, end);
	conquer(array, start, mid, end);
}

/**
 * merge_sort - execute a merge sorting
 * @size: number of elements
 * @array: array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	divide(array, 0, size - 1);
}
