
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: is the head of the list
 * @number: is the value
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL;
	listint_t *current = *head, *next = NULL;

	new = (listint_t *)malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (!*head)
		*head = new;
	else if ((*head)->n > number)
	{
		new->next = (*head);
		*head = new;
	}
	else
	{
		while (current)
		{
			next = current->next;
			if (number >= current->n && (!next || number < next->n))
			{
				new->next = next;
				current->next = new;
				break;
			}
			current = next;
		}
	}
	return (new);
}
