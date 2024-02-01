#include "binary_trees.h"

/**
 * bst_search - Searches for value
 * @tree: Pointer to tree node
 * @value: Value
 *
 * Return: Func must return null
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
