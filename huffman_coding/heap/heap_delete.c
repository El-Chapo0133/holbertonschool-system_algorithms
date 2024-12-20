/*
 * ===========================================================================
 *
 *       Filename:  heap_delete.c
 *
 *    Description: Write a function that deallocates a heap
 *
 *        Version:  1.0
 *        Created:  20.12.2024 09:56:52
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
 * recursivly_delete_all_nodes - use recursion to delete all nodes
 * @node: node to delete
 * @free_data: ptr to function to free data
 *
 * Return: void
 */
void recursivly_delete_all_nodes(binary_tree_node_t *node,
		void (*free_data)(void *))
{
	if (!node)
		return;
	recursivly_delete_all_nodes(node->left, free_data);
	recursivly_delete_all_nodes(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);
}

/**
 * heap_delete - delete all nodes
 * @heap: heap
 * @free_data: ptr to function to free data
 *
 * Return: void
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	if (!heap->root)
	{
		free(heap);
		return;
	}

	recursivly_delete_all_nodes(heap->root, free_data);
	free(heap);	
}
