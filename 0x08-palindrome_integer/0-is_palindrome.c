#include "palindrome.h"

/**
 * is_palindrome - determines if a given number is palindrome
 * @n: the given number
 * Return: 1 if it is a palindrome, 0 in otherwise
 */
int is_palindrome(unsigned long n)
{
	int arr[20] = {0};
	int h = 0, l = 0;
	unsigned long power = 1;

	while ((n / power) >= 1)
	{
		arr[h] = (n / power) % 10;
		power *= 10, h++;
	}

	h--;
	while (h > l)
	{
		if (arr[l] != arr[h])
			return (0);
		l++, h--;
	}

	return (1);
}
