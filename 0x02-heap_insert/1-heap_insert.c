#include "binary_trees.h"

/**
 * most_left - search the node where must be added the new
 * node
 * @node: is the current node on the heap tree
 * Return: a node that contains one or none child
 */
heap_t *most_left(heap_t *node)
{
	heap_t *l = NULL, *r = NULL;

	if (!node)
		return (NULL);
	l = node->left, r = node->right;
	if (l && r)
	{
		if (!l->left || !l->right)
			return (l);
		else if (!r->left || !r->right)
			return (r);
		else
			return (most_left(l));
	}
	else if (!l || !r)
		return (node);
	return (NULL);
}

/**
 * mantain_propertie - check that the given node has the max heap
 * propertie. In otherwise, do the correspondin operation to save it
 * @node: node to be evaluated
 */
void mantain_propertie(heap_t *node)
{
	heap_t *parent, *sibling, *ancestor;

	if (!node || !node->parent)
		return;
	parent = node->parent, ancestor = parent->parent;
	sibling = (parent->right == node) ? parent->left : NULL;
	if (node->n > parent->n)
	{
		if (ancestor)
		{
			if (parent == ancestor->left)
				ancestor->left = node;
			else
				ancestor->right = node;
		}
		node->parent = ancestor;
		parent->parent = node;
		parent->right = node->right;
		parent->left = node->left;
		if (node->left)
			node->left->parent = parent;
		if (node->right)
			node->right->parent = parent;
		if (sibling)
		{
			node->left = sibling;
			sibling->parent = node;
			node->right = parent;
		}
		else
			node->left = parent;
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
	if (!root)
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
