#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid
 * @tree: Pointer to tree node
 * @lo: Lowest node
 * @hi: Hghest node
 *
 * Return: Return 1 if tree is valid
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree
 * @tree: Pointer to tree node
 *
 * Return: Return 1 if tree is valid
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
