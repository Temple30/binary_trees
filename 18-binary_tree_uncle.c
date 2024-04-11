#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle.
 * Return: A pointer to the uncle node, or NULL if node is NULL,
 * the parent is NULL, the grandparent is NULL, or node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	binary_tree_t *grandparent = node->parent->parent;

	/*
	 * If node's parent is the left child of the grandparent,
	 * return the right child of the grandparent
	 */
	if (grandparent->left == node->parent)
		return (grandparent->right);

	/*
	 * If node's parent is the right child of the grandparent,
	 * return the left child of the grandparent
	 */
	if (grandparent->right == node->parent)
		return (grandparent->left);

	return (NULL); /* Node has no uncle */
}
