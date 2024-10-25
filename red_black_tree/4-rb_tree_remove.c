#include "rb_trees.h"
#include "4-rb_tree_remove.h"


/**
 * rb_tree_remove - remove a node from the tree
 * AND keep the balancing
 * @root: root
 * @n: node to find and delete
 *
 * Return: new root
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *temp_node, *node_to_remove = find_node_to_remove(root, n);
	if (!node_to_remove)
		return (NULL);

	if (node_to_remove->left == NULL && node_to_remove->right == NULL)
	{
		temp_node = find_smallest(node_to_remove->right);
		transplant(&root, temp_node, NULL);
		transplant(&root, node_to_remove, temp_node);
		temp_node->left = node_to_remove->left;

	}
	else if (node_to_remove->left == NULL)
	{
		transplant(&root, node_to_remove, node_to_remove->right);
		repear_deletion();
	}
	else if (node_to_remove->right == NULL)
	{
		transplant(&root, node_to_remove, node_to_remove->left);
		repear_deletion();
	}

	free(node_to_remove);
	return (root);
}

void repear_deletion(rb_tree_t **root, rb_tree_t *to_fix)
{
	rb_tree_t *brother = NULL;
	int is_right = 0;

	while (to_fix != *root && to_fix->color == BLACK)
	{
		if (to_fix == to_fix->parent->left)
		{
			brother = to_fix->parent->right;
			if (brother->color == RED)
			{
				brother->color = BLACK;
				to_fix->parent->color = RED;
				rotate_left(to_fix->parent);
				brother = to_fix->parent->right;
			}
			if (brother->left->color == BLACK && brother->right->color == BLACK)
			{
				brother->color = RED;
				to_fix = to_fix->parent;
			}
			else
			{
				if (brother->right->color == BLACK)
				{
					brother->left->color = BLACK;
					brother->color = RED;
					rotate_right(brother);
					brother = to_fix->parent->right;
				}
				brother->color = to_fix->parent->color;
				to_fix->parent->color = BLACK;
				rotate_left(to_fix->parent);
				to_fix = *root;
			}
		}
		else
		{
			brother = to_fix->parent->left;
			if (brother->color == RED)
			{
				brother->color = BLACK;
				to_fix->parent->color = RED;
				rotate_right(to_fix->parent);
				brother = to_fix->parent->left;
			}
			if (brother->right->color == BLACK && brother->left->color == BLACK)
			{
				brother->color = RED;
				to_fix = to_fix->parent;
			}
			else
			{
				if (brother->left->color == BLACK)
				{
					
				}
			}
		}
	}
}


/**
 * find_smallest - find the smallest value amoung the nodes
 * @root: startup root to browse
 *
 * Return: node with the smallest value
 */
rb_tree_t *find_smallest(rb_tree_t *root)
{
	if (!root)
		return (NULL);
	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}

/**
 * transplant - move the subtrees within the tree
 * fixing the child left and right is the caller's responsibility
 * @root: current root
 * @to_remove: node to be removed
 * @child: one of to_remove's child
 *
 * Return: void
 */
void transplant(rb_tree_t **root, rb_tree_t *to_remove, rb_tree_t *child)
{
	if (to_remove->parent == NULL) /* when to_remove is the root */
		(*root) = child;
	else if (to_remove == to_remove->parent->left) /* left case */
		to_remove->parent->left = child;
	else /* right case */
		to_remove->parent->right = child;
	/* fix parental issues */
	child->parent = to_remove->parent;
}

/**
 * find_node_to_remove - browse the tree to find the node to remove
 * @root: root of the tree
 * @n: value to find
 *
 * Return: the node to remove, NULL instead
 */
rb_tree_t *find_node_to_remove(rb_tree_t *root, int n)
{
	rb_tree_t *node = root;
	while (node)
	{
		if (node->n == n)
			return (node);
		if (node->n > n)
			node = node->left;
		else
			node = node->right;
	}
	return (NULL);
}



/**
 * rb_tree_rotate_left - left child of root becomes new root, tree rotated
 * @tree: pointer
 * Return: new root node
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *pivot = NULL;

	if (!tree)
		return (NULL);

	pivot = tree->right;

	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}


/**
 * rb_tree_rotate_right - tree rotated
 * @tree: pointer
 * Return: new root node
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *pivot = NULL;

	if (!tree)
		return (NULL);

	pivot = tree->left;

	tree->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}

	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}
