/*
 * ===========================================================================
 *
 *       Filename:  heap_insert.c
 *
 *    Description: Write a function that inserts a value in a Min Binary Heap
 *
 *        Version:  1.0
 *        Created:  13.12.2024 10:30:09
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
 * try_to_insert - try to insert the new node in the BST
 * @heap: heap
 * @node: node to insert
 *
 * Return: 1 if well inserted, 0 otherwise
 */
int try_to_insert(heap_t heap, binary_tree_node_t *node)
{
	int cmp;
	binary_tree_node_t *temp = heap->root;

	while (temp)
	{
		cmp = heap->data_cmp(node->data, temp->data);
		
		/* if node - temp > 0, if node is greater than temp */
		if (cmp > 0 && temp->right)
			temp = temp->right;
		else if (cmp < 0 && temp->left)
			temp = temp->left;
		else
			return (0);
	}

	if (cmp > 0)
		temp->right = node;
	else
		temp->left = node;
	return (1);
}

/**
 * heap_insert - insert a node in a given binary tree
 * @heap: heap of the binary tree
 * @data: data to insert
 *
 * Return: newly created and inserted node
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node = NULL;
	int is_inserted = 0;

	if (!heap || data == NULL)
		return (NULL);

	node = binary_tree_node(NULL, data);
	if (!node)
		return (NULL);

	if (!heap->root)
		return (heap->size++, heap->root = node, node);

	is_inserted = try_to_insert(heap, node);

	if (!is_inserted)
	{
		free(node);
		return (NULL);
	}

	if (!node->parent)
		heap->root = node;
	heap->size++;
	return (node);
}
