#include "binary_trees.h"
/**
 * binary_tree_height_add - Measures the addition of heights
 * @tree: Pointer to tree node
 *
 * Return: Height
 */
size_t binary_tree_height_add(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	height_left = 1 + binary_tree_height_add(tree->left);

	height_right = 1 + binary_tree_height_add(tree->right);

	if (height_left > height_right)
		return (height_left);
	return (height_right);

}
/**
 * printLevel - Print level
 * @tree: Pointer to tree node
 * @level: Levels
 * @func: Function
 * Return: Height or 0 if tree is NULL
 */
void printLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printLevel(tree->left, level - 1, func);
		printLevel(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree
 * @tree: Pointer to tree
 * @func: Function
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i = 1;
	int height = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height_add(tree) + 1;

	while (i <= height)
	{
		printLevel(tree, i, func);
		i++;
	}
}
