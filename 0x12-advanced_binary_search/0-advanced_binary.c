#include "search_algos.h"

/**
 * advanced_binary - performe a variance of the binary search where
 * found the first occurence of the found value
 *
 * @array: the given data
 * @size: sizeo of the data
 * @value: the given value to be searched
 *
 * Return:  the index of the first occurrence, -1 when no founded
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 0, middle = 0, index = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	middle = (size - 1) / 2;
	if (array[middle] == value)
	{
		if (size == 1 || array[middle - 1] < value)
			return (middle);
	}
	else if (size == 1)
	{
		return (-1);
	}
	if (array[middle] < value)
	{
		index += middle + 1, array += middle + 1;
		if (size % 2 != 0)
			middle--;
	}
	middle++;
	tmp = advanced_binary(array, middle, value);
	if (tmp != -1)
		return (tmp + index);
	return (-1);
}
