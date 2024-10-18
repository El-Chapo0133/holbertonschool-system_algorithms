#include "rb_trees.h"
#include "1-rb_tree_insert.h"
#include "tree_utils.h"

/**
 * rb_tree_insert - insert new node in red black tree
 * @tree: parent node
 * @value: value to insert
 *
 * Return: newly created node
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *parent, *uncle, *grand_parent, *new_node;

	if (!tree) /* NULL check */
	{
		tree = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}

	new_node = insert_at_right_place(tree, value);
	if (!new_node) /* Memory error :( */
		return (NULL);
	uncle = get_uncle(new_node);
	if (!uncle) /* NULL check uncle, grandparent or parent is NULL*/
		return (NULL)
	parent = new_node->parent;
	grand_parent = parent->parent;

}

/**
 * insert_at_right_place - insert new node at the right place
 * of the current tree
 * @tree: non-NULL parent node
 * @value: value of the new node
 *
 * Return: new created node
 */
rb_tree_t insert_at_right_place(rb_tree_t **tree, int value)
{
	rb_tree_t *discover, *parent;

	/* start looking where to put new node */
	discover = *tree;
	while (discover)
	{
		parent = discover;
		if (discover->n < value)
			discover = discover->left;
		else
			discover = discover->right;
	}
	dicover = rb_tree_node(parent, value, RED);
	/* update parent links */
	if (value < parent->n) /* place smaller value on the left */
		parent->left = discover;
	else
		parent->right = discover;
	return (discover);
}

int repear_rb_tree(rb_tree_t **tree)
{

}

