#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If the tree is full - 1. Otherwise - 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*
	 * If a node has either no children or
	 * both children, recursively check its children
	 */
	if ((tree->left == NULL && tree->right == NULL) ||
			(tree->left != NULL && tree->right != NULL))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If a node violates the full binary tree property, return 0 */
	return (0);
}
