
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: is the head of the list
 * @number: is the value
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *current = *head, *next = NULL, *tmp = NULL;

	new = (listint_t *)malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (!*head)
		*head = new;
	do
	{
		if (!current)
		{
			current = new;
			break;
		}
		next = current->next;
		if (!next)
		{
			current->next = new;
			break;
		}
		if (current->n <= number && next->n > number)
		{
			tmp = next;
			current->next = new;
			new->next = tmp;
			break;
		}
		current = next;
	} while (current);
	return (new);
}
