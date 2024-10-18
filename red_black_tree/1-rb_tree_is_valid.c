#include "rb_trees.h"
#include "1-rb_tree_is_valid.h"


/**
 * rb_tree_is_valid - check if a rb_tree is valid
 * @tree: parent node
 *
 * Return: bool
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree)
		return (false);
	if (tree->color != BLACK)
		return (false);

	if (!check_bst(tree))
		return (false);
	if (check_height(tree) > 1) /* should be 0 or 1 */
		return (false);

	return (true);
}

/**
 * check_height - recursivly check the height of the tree
 * the tree should be balanced and so not have an unbalanced side
 * @tree: parent node
 *
 * Return: positive value of the unbalancing
 */
int check_height(const rb_tree_t *tree)
{
	/* balancing value */
	int difference = 0;

	if (!tree) /* NULL check */
		return (false);

	difference = check_height(tree->left) - check_height(tree->right);
	if (difference >= 0)
		return (difference + 1);
	return (-difference + 1); /* negative difference to get a positive */
}

/**
 * check_bst - check if the tree is bst
 * meaning smaller values on the left and bigger on the right
 * @tree: parent node
 *
 * Return: bool
 */
int check_bst(const rb_tree_t *tree)
{
	if (!tree) /* NULL check */
		return (false);
	
	return (recursive_bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * recursive_bst_check - recursivly check is tree is bst
 * meaning smaller values on the left and bigger on the right
 * @tree: node
 * @min: min acceptable value
 * @max: max acceptable value
 *
 * Return: bool
 */
int recursive_bst_check(const rb_tree_t *tree, int min, int max)
{
	if (!tree) /* NULL check */
		return (true);
	if (tree->n < min || tree->n > max)
		return (false);
	
	return (recursive_bst_check(tree->left, min, tree->n - 1) &&
	        recursive_bst_check(tree->right, tree->n + 1, max));
}
