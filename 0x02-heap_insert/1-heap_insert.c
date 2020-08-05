#include "binary_trees.h"

/**
 * most_left - search the node where must be added the new
 * node
 * @node: is the current node on the heap tree
 * Return: a node that contains one or none child
 */
heap_t *most_left(heap_t *node)
{
	heap_t *l = NULL, *r = NULL, *current = node;

	if (!current)
		return (NULL);

	while (current)
	{
		l = current->left, r = current->right;
		if (l && r)
		{
			if (!l->left || !l->right)
				return (l);
			else if (!r->left || !r->right)
				return (r);

			current = l;
			continue;
		}
		else if (!l || !r)
			return (current);
	}
	return (NULL);
}

/**
 * swap - swap a node with its parent
 * @node: is the given node
 */
void swap(heap_t *node)
{
	heap_t *parent = NULL, *sibling = NULL, *ancestor = NULL;
	int is_left = 0;

	if (!node || !node->parent)
		return;
	parent = node->parent, ancestor = parent->parent;
	is_left = parent->left == node;
	sibling = (is_left) ? parent->right : parent->left;

	if (ancestor)
	{
		if (ancestor->left == parent)
			ancestor->left = node;
		else
			ancestor->right = node;
	}
	node->parent = ancestor;
	parent->parent = node;
	parent->right = node->right;
	if (node->right)
		node->right->parent = parent;
	parent->left = node->left;
	if (node->left)
		node->left->parent = parent;
	if (sibling)
		sibling->parent = node;
	if (is_left)
	{
		node->left = parent;
		node->right = sibling;
	}
	else
	{
		node->right = parent;
		node->left = sibling;
	}
}

/**
 * mantain_propertie - check that the given node has the max heap
 * propertie. In otherwise, do the correspondin operation to save it
 * @node: node to be evaluated
 */
void mantain_propertie(heap_t *node)
{
	if (!node || !node->parent)
		return;
	if (node->n > node->parent->n)
	{
		swap(node);
		mantain_propertie(node);
	}
}

/**
 * heap_insert - it inserts a new node into the heap
 * @root: a double pointer to the root of the tree
 * @value: is the value of the new node
 * Return: a pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *leaft = NULL;

	new = (heap_t *)binary_tree_node(NULL, value);
	if (!root || !new)
		return (NULL);
	if (!*root)
	{
		*root = new;
		return (new);
	}
	leaft = most_left(*root);

	if (!leaft->left)
		leaft->left = new;
	else
		leaft->right = new;
	new->parent = leaft;
	mantain_propertie(new);
	if (!new->parent)
		*root = new;
	return (new);
}
