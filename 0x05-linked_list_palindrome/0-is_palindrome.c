#include "lists.h"

/**
 * put - put a new node in the stack
 * @stack: is the stack list
 * @origin: is the origin node to add
 */
void put(listint_t **stack, listint_t *origin)
{
	listint_t *newNode = NULL;

	if (!stack)
		return;

	newNode = malloc(sizeof(listint_t *));
	if (!newNode)
		exit(1);

	newNode->n = origin->n;
	newNode->next = (*stack);
	*stack = newNode;
}

/**
 * freeStack - free a stack
 * @stack: is the stack
 */
void freeStack(listint_t *stack)
{
	listint_t *next = NULL, *index = stack;

	while (index)
	{
		next = index->next;
		free(index);
		index = next;
	}
}

/**
 * is_palindrome - determines if a linked list is a palindrome
 * @head: is the head of the linkedlist
 * Return: 1 if it is a palindrome, 0 in otherwise
 */
int is_palindrome(listint_t **head)
{
	short isPalindrome = 1;
	listint_t *index = *head, *stack = NULL, *stackIndex = NULL;
	size_t size = 0, mid = 0, i = 0;

	if (!head || !(*head))
		return (isPalindrome);

	while (index)
	{
		put(&stack, index);
		index = index->next;
		size++;
	}

	mid = size / 2, index = *head, stackIndex = stack;
	while (i < mid && isPalindrome)
	{
		if (index->n != stackIndex->n)
			isPalindrome = 0;

		index = index->next;
		stackIndex = stackIndex->next;
		i++;
	}

	freeStack(stack);
	return (isPalindrome);
}
