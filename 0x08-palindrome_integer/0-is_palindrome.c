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
	unsigned long power = n;

	do {
		power /= 10, h++;
	} while (power);

	if (h == 1)
		return (1);

	for (l = 0; l < h; l++)
		arr[h - 1 - l] = n % 10, n /= 10;

	for (l = 0; l < h; l++)
	{
		if (l > h / 2)
			break;
		else if (arr[l] == arr[h - 1 - l])
			continue;
		else
			return (0);
	}
	return (1);
}
