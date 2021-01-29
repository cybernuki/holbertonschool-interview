#include "lists.h"
/**
 * find_listint_loop - find a loop inside a linked list, return null
 * @head: is the header of the linked list
 * Return: a pointer to the loop node, or null
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *last;

	first = head;
	last = first;
	while (first && last && last->next)
	{
		first = first->next;
		last = last->next->next;
		if (first == last)
		{
			first = head;
			while (first && last)
			{
				if (first == last)
					return (first);
				first = first->next;
				last = last->next;
			}
		}
	}
	return ('\0');
}
