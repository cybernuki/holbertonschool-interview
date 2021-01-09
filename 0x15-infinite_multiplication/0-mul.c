#include "holberton.h"

/**
  * _strlen - returns the lenght of a given string.
  * @string: The given string.
  * Return: lenght of the given string.
  */
int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
		i++;

	return (i);
}

/**
 * error_handler - handle error
 */
void error_handler(void)
{
	int i = 0;
	char *error = "Error";

	while (1)
	{
		if (error[i] == '\0')
		{
			_putchar('\n');
			exit(98);
		}
		_putchar(error[i++]);
	}
}

/**
 * main - main.
 * @argc: arguments.
 * @argv: arguments.
 * Return: int.
 */
int main(int argc, char **argv)
{
	char *result;
	int num1 = 0, num2 = 0, total = 0, value1 = 0, value2 = 0;
	int i = 0, j = 0, n = 0, k = 0, sum = 0, partial = 0;

	if (argc != 3)
		error_handler();
	num1 = _strlen(argv[1]), num2 = _strlen(argv[2]), total = num1 + num2;
	result = malloc(num1 + num2);
	if (result == NULL)
		exit(98);
	for (i = 0; i <= total; i++)
		result[i] = (i != total) ? '0' : '\0';
	for (i = num1 - 1; i >= 0; i--, n++, k = 0, partial = 0)
	{
		value1 = argv[1][i] - '0';
		for (j = num2 - 1; j >= 0; j--, k++)
		{
			value2 = argv[2][j] - '0';
			sum = value1 * value2 + (result[k + n] - '0') + partial;
			partial = sum / 10;
			result[k + n] = (sum % 10 + '0');
		}
		if (partial > 0)
			result[k + n] = (partial + (result[k + n] - '0')) + '0';
	}
	i = total;
	while (i >= 0 && result[i - 1] == '0')
		i--;
	while (1)
	{
		if (i == 0)
		{
			_putchar('\n');
			break;
		}
		_putchar(result[i-- - 1]);
	}
	free(result);
	return (0);
}
