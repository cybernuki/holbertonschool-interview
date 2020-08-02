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
 * mantain_propertie - check that the given node has the max heap
 * propertie. In otherwise, do the correspondin operation to save it
 * @node: node to be evaluated
 */
void mantain_propertie(heap_t *node)
{
	heap_t *parent, *sibling, *ancestor, *current = node;

	while (!current || !current->parent)
	{
		parent = current->parent, ancestor = current->parent;
		sibling = (parent->right == current) ? parent->left : NULL;
		if (current->n > parent->n)
		{
			if (ancestor)
			{
				if (parent == ancestor->left)
					ancestor->left = current;
				else
					ancestor->right = current;
			}
			current->parent = ancestor;
			parent->parent = current;
			parent->right = current->right;
			parent->left = current->left;
			if (current->left)
				current->left->parent = parent;
			if (current->right)
				current->right->parent = parent;
			if (sibling)
			{
				current->left = sibling;
				sibling->parent = current;
				current->right = parent;
			}
			else
				current->left = parent;
		}
		else
			break;
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
