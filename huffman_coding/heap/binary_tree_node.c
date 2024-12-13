/*
 * ===========================================================================
 *
 *       Filename:  cinary_tree_node.c
 *
 *    Description: Write a function that creates a generic Binary Tree node
 *
 *        Version:  1.0
 *        Created:  13.12.2024 10:26:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Lévêque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ===========================================================================
 */

#include "heap.h"


/**
 * binary_tree_node - create a binary_tree_node_t
 * @parent: node parent
 * @data: node data
 *
 * Return: newly created binary_tree_node_t
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node = malloc(sizeof(binary_tree_node_t));

	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);

}
