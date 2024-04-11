#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling.
 * Return: A pointer to the sibling node, or NULL if node is NULL,
 *         the parent is NULL, or node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/*
	 * If the node is the left child,
	 * return the right child (if exists) of the parent
	 */
	if (node->parent->left == node)
		return (node->parent->right);

	/*
	 * If the node is the right child,
	 * return the left child (if exists) of the parent
	 */
	if (node->parent->right == node)
		return (node->parent->left);

	return (NULL); /* Node has no sibling */
}
