#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is the parent node of this new node
 * @value: is the value of this new node
 * Return: a new binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
