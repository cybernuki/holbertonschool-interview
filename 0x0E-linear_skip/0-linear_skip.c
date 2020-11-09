#include "search.h"

/**
 * linear_skip - do a search by the given value
 * @list: is the given list
 * @value: is the value to be searched
 * Return: the node with the value or null if no found.
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *express = NULL, *lastIndex = NULL;

	while (current)
	{
		express = current->express;

		if (!express)
		{
			lastIndex = current;
			while (lastIndex->next)
				lastIndex = lastIndex->next;
			printf("Value found between indexes [%ld] and [%ld]\n",
				   current->index,
				   lastIndex->index);
		}
		else
		{
			printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
			if (value > express->n)
			{
				current = express;
				continue;
			}
			else
				printf("Value found between indexes [%ld] and [%ld]\n",
					   current->index,
					   express->index);
		}

		while (current)
		{
			printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
			if (value == current->n)
				return (current);

			current = current->next;
		}
	}

	return (NULL);
}
