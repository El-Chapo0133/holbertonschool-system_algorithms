#include "tree_utils.h"


/**
 * get_uncle - get uncle of the given node
 * @tree: node to get the uncle
 *
 * Return: node that is the uncle
 */
rb_tree_t get_uncle(const rb_tree_t *tree)
{
	rb_tree_t *parent;

	if (!tree || !tree->parent || !tree->parent->parent) /* NULL check */
		return (NULL);
	parent = tree->parent;
	
	/**
	 *    grandparent
	 *    /       \
	 *  uncle    parent
	 *              \
	 *              tree
	 */
	if (parent->parent->left == parent)
		return (parent->parent->right);
	return (parent->parent->left);
}
