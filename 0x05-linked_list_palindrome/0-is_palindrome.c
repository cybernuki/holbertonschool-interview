#include "lists.h"

/**
 * is_palindrome - determines if a linked list is a palindrome
 * @head: is the head of the linkedlist
 * Return: 1 if it is a palindrome, 0 in otherwise
 */
int is_palindrome(listint_t **head)
{
	short isPalindrome = 1;
	int arr[2048];
	int h = 0, l = 0;
	listint_t *index = NULL;

	if (!head || !(*head) || !(*head)->next)
		return (isPalindrome);

	while (index)
	{
		arr[l++] = index->n;
		index = index->next;
	}

	while (h < l && isPalindrome)
	{
		if (arr[h] != arr[l])
			isPalindrome = 0;
		h++, l--;
	}

	return (isPalindrome);
}
