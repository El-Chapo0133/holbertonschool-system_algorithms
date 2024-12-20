/*
 * ===========================================================================
 *
 *       Filename:  heap_extract.c
 *
 *    Description: Write a function that extracts the root value of a Min Binary Heap
 *
 *        Version:  1.0
 *        Created:  20.12.2024 09:32:08
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
 * heapify_from_root - heapify a heap tree from root
 * @heap: heap
 *
 * Return: void
 */
void heapify_from_root(heap_t *heap)
{
	binary_tree_node_t *node, *child;
	void *temp = NULL;

	node = heap->root;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = heap->data_cmp(node->left->data, node->right->data) <= 0 ?
				node->left : node->right;
		if (heap->data_cmp(node->data, child->data) < 0)
			break;
		temp = node->data;
		node->data = child->data;
		child->data = temp;
		node = child;
	}	
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: heap
 *
 * Return: data of root
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *node;
	size_t bit;
	void *data;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;
	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size = 0;
		return (data);
	}

	for (bit = 1; bit <= heap->size; bit <<= 1)
		;
	bit >>= 2;
	for (node = heap->root; bit > 0; bit >>= 1)
		node = heap->size & bit ? node->right : node->left;
	heap->root->data = node->data;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	heap->size--;
	free(node);
	heapify_from_root(heap);
	return (data);
}
