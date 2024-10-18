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
	if (check_height(tree) != 0)
		return (false);

	return (true);
}

/**
 * check_height - recursivly check the height of the tree
 * the tree should be balanced and so not have an unbalanced side
 * @tree: parent node
 *
 * Return: value of the unbalancing
 */
int check_height(const rb_tree_t *tree)
{
	/* balancing value */
	int difference = 0;

	if (!tree) /* NULL check */
		return (false);

	difference = check_height(tree->left) - check_height(tree->right);
	return (-difference + 1);
}

int check_bst(const rb_tree_t *tree)
{
	if (!tree) /* NULL check */
		return (false);
	
	return (recursive_bst_check(tree, INT_MIN, INT_MAX));
}

int recursive_bst_check(const rb_tree_t *tree, int min, int max)
{
	if (!tree) /* NULL check */
		return (true);
	if (tree->n < min || tree->n > max)
		return (false);
	
	return (recursive_bst_check(tree->left, min, tree->n - 1) &&
	        recursive_bst_check(tree->right, tree->n + 1, max));
}
