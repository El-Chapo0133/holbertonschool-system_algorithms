#include "rb_trees.h"
#include "1-rb_tree_is_valid.h"


int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree)
		return (false);
	if (tree->color != BLACK)
		return (false);

	if (!check_bst(tree))
		return (false);
	if (check_height(tree) > 1)
		return (false);

	return (true);
}

int check_height(const rb_tree_t *tree)
{
	int difference = 0;

	if (!tree) /* NULL check */
		return (false);

	difference = check_height(tree->left) - check_height(tree->right);
	if (difference >= 0)
		return (difference + 1);
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
