#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 * Return: A pointer to the lowest common ancestor node,
 * or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	/* Base cases */
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	/* Recursive case */
	binary_tree_t *ancestor = binary_trees_ancestor
		(first->parent, second->parent);

	/* If ancestor is NULL, no common ancestor found */
	if (ancestor == NULL)
		return (NULL);

	/* If ancestor is either first or second, it's the LCA */
	if (ancestor == first || ancestor == second)
		return (ancestor);

	/*
	 * If both first and second are found in the
	 * subtree rooted at ancestor, ancestor is the LCA
	 */
	if (binary_tree_size(ancestor, first) && binary_tree_size(ancestor, second))
		return (ancestor);

	/*
	 * If only one of the nodes is found in
	 * the subtree rooted at ancestor, return that node
	 */
	if (binary_tree_size(ancestor, first))
		return ((binary_tree_t *)first);
	else
		return ((binary_tree_t *)second);
}

/**
 * binary_tree_find - Checks if a node exists in a binary tree.
 * @tree: A pointer to the root node of the tree to check.
 * @node: A pointer to the node to find.
 * Return: 1 if the node exists in the tree, 0 otherwise.
 */
int binary_tree_find(const binary_tree_t *tree, const binary_tree_t *node)
{
	if (tree == NULL)
		return (0);

	if (tree == node)
		return (1);

	return (binary_tree_find(tree->left, node) ||
			binary_tree_find(tree->right, node));
}
