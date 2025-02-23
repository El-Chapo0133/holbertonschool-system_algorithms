/*
 * ==========================================================================
 *
 *       Filename:  1-nary_tree_delete.c
 *
 *    Description:  deallocates an entire N-ary tree
 *
 *        Version:  1.0
 *        Created:  23.02.2025 17:13:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "nary_trees.h"

/**
 * nary_tree_delete - deallocates tree
 * @tree: pointer
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *temp;

	if (!tree)
		return;

	while (tree->children)
	{
		temp = tree->children;
		tree->children = tree->children->next;
		nary_tree_delete(temp);
	}

	if (tree->content)
		free(tree->content);

	free(tree);
}
