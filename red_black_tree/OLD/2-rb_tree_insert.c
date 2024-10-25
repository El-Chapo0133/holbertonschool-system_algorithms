#include "2-rb_tree_insert.h"

/**
 * rb_tree_insert - insert new node in red black tree
 * @tree: parent node
 * @value: value to insert
 *
 * Return: newly created node
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node;

	if (!*tree) /* NULL check */
	{
		(*tree) = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}

	new_node = insert_at_right_place(tree, value);
	if (!new_node) /* Memory error :( */
		return (NULL);
	
	repear_rb_tree(tree, new_node);
	return (new_node);
}

/**
 * insert_at_right_place - insert new node at the right place
 * of the current tree
 * @tree: non-NULL parent node
 * @value: value of the new node
 *
 * Return: new created node
 */
rb_tree_t *insert_at_right_place(rb_tree_t **tree, int value)
{
	rb_tree_t *discover, *parent;

	/* start looking where to put new node */
	discover = *tree;
	while (discover)
	{
		parent = discover;
		if (value == discover->n)
			return (NULL);
		else if (discover->n < value)
			discover = discover->left;
		else
			discover = discover->right;
	}
	discover = rb_tree_node(parent, value, RED);
	if (!discover) /* NULL check */
		return (NULL);
	
	/* update parent links */
	if (value < parent->n) /* place smaller value on the left */
		parent->left = discover;
	else
		parent->right = discover;
	return (discover);
}

void repear_rb_tree(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *parent = NULL;
	rb_tree_t *grand_parent = NULL;

	while (new_node != *tree &&
		new_node->color == RED &&
		new_node->parent->color == RED)
	{
		parent = new_node->parent;
		grand_parent = parent->parent;
		rotate_cases(tree, &new_node, parent, grand_parent,
				!(parent == grand_parent->left));
	}

	(*tree)->color = BLACK;
}


void rotate_cases(rb_tree_t **tree, rb_tree_t **new_node, rb_tree_t *parent,
		rb_tree_t *grand_parent, int is_right)
{
	rb_tree_t *uncle = is_right ? grand_parent->left : grand_parent->right;

	if (uncle && uncle->color == RED)
	{
		grand_parent->color = RED;
		parent->color = BLACK;
		uncle->color = BLACK;
		*new_node = grand_parent;
	}
	else
	{
		/* left case */
		if (!is_right && (*new_node == parent->right))
		{
			rotate_left(tree, parent);
			*new_node = parent;
			parent = (*new_node)->parent;
		}
		/* right case */
		if (is_right && (*new_node == parent->left))
		{
			rotate_right(tree, parent);
			*new_node = parent;
			parent = (*new_node)->parent;
		}
		/* Uncle is BLACK and new_node is the left child */
		is_right ? rotate_left(tree, grand_parent) : rotate_right(tree, grand_parent);
		swap_colors(parent, grand_parent);
		*new_node = parent;
	}
}

void rotate_right(rb_tree_t **tree, rb_tree_t *grand_parent)
{
	rb_tree_t *parent = grand_parent->left;
	
	grand_parent->left = parent->right;

	if (parent->right)
		parent->right->parent = grand_parent;
	parent->parent = grand_parent->parent;

	if (!grand_parent->parent)
		*tree = parent;
	else if (grand_parent == grand_parent->parent->left)
		grand_parent->parent->left = parent;
	else
		grand_parent->parent->right = parent;

	parent->right = grand_parent;
	grand_parent->parent = parent;
}
void rotate_left(rb_tree_t **tree, rb_tree_t *parent)
{
	rb_tree_t *right_child = parent->right;

	parent->right = right_child->left;
	if (parent->right)
		parent->right->parent = parent;

	right_child->parent = parent->parent;
	if (!parent->parent)
		*tree = right_child;
	else if (parent == parent->parent->left)
		parent->parent->left = right_child;
	else
		parent->parent->right = right_child;

	right_child->left = parent;
	parent->parent = right_child;
}

/**
 * swap_colors - swap the colors of two given nodes
 * @node1: first node
 * @node2: second node
 *
 * Return: void
 */
void swap_colors(rb_tree_t *node1, rb_tree_t *node2)
{
	rb_color_t node1_color = node1->color;
	node1->color = node2->color;
	node2->color = node1_color;
}
