#include "holberton.h"

/**
 * display_error - Display the error message.
 * Return: Void.
 */
void display_error(void)
{
	int i;
	char *error = "Error";

	for (i = 0; error[i] != '\0'; i++)
		_putchar(error[i]);
	_putchar('\n');
	exit(98);
}

/**
  * _strlen - Return the lenght of a string.
  * @s: The string.
  * Return: Lenght of a string.
  */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * main - Multiply to big numbers.
 * @argc: Number of arguments.
 * @argv: Value of the arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *result;
	int i, j, w, num1, num2, val1, val2, n = 0, k = 0, sum = 0, partial = 0;

	if (argc != 3)
		display_error();

	num1 = _strlen(argv[1]);
	num2 = _strlen(argv[2]);

	result = malloc(num1 + num2);
	if (result == NULL)
		exit(98);
	for (i = 0; i < num1 + num2; i++)
		result[i] = '0';
	result[i] = '\0';
	for (j = num1 - 1; j >= 0; j--, n++, k = 0, partial = 0)
	{
		val1 = argv[1][j] - '0';
		for (w = num2 - 1; w >= 0; w--, k++)
		{
			val2 = argv[2][w] - '0';
			sum = val1 * val2 + (result[k + n] - '0') + partial;
			partial = sum / 10;
			result[k + n] = (sum % 10 + '0');
		}
		if (partial > 0)
			result[k + n] = (partial + (result[k + n] - '0')) + '0';
	}
	i = num1 + num2;
	while (i >= 0 && result[i - 1] == '0')
		i--;
	while (i > 0)
	{
		_putchar(result[i - 1]);
		i--;
	}
	_putchar('\n');
	free(result);
	return (0);
}
