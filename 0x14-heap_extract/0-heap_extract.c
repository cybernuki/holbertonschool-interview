#include "binary_trees.h"

/**
 * heapify_down - restores the min heap property from root down
 * @heap: pointer to heap struct
 */
void heapify_down(heap_t *heap)
{
	heap_t *node = heap, *child = NULL;
	int tmp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = (node->left->n - node->right->n) >= 0
						? node->left
						: node->right;
		if ((node->n - child->n) > 0)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		node = child;
	}
}

/**
 * setBitNumber - set the most significant bite
 * for the given number
 * @n: is the given number
 * Return: the most significant bit of the given number
 */
size_t setBitNumber(size_t n)
{
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n = n + 1;
	return (n >> 1);
}

/**
 * getSize -get size of the heap
 * @root: is the root of the heap
 * Return: the size
 */
size_t getSize(heap_t *root)
{
	if (!root)
		return (0);

	return (getSize(root->left) + getSize(root->right) + 1);
}
/**
 * heap_extract -extract a node from the heap
 *
 * @root: is the root of the heap
 * Return: value extracted, 0 on error
 */
int heap_extract(heap_t **root)
{
	heap_t *lastNode = NULL, *parent = NULL;
	int failure = 0, data = 0;
	size_t path = 0, size = 0;

	size = getSize(*root);
	if (!root || size == 0)
		return (failure);

	path = setBitNumber(size) >> 1;
	if (size == 1)
	{
		data = (*root)->n;
		free(*root), *root = NULL;
		return (data);
	}

	for (lastNode = *root; path; path >>= 1)
		lastNode = (path & size) ? lastNode->right : lastNode->left;

	data = (*root)->n;
	(*root)->n = lastNode->n;
	parent = lastNode->parent, free(lastNode);
	if ((size--) & 1)
		parent->right = NULL;
	else
		parent->left = NULL;

	heapify_down(*root);
	return (data);
}
