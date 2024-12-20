/*
 * ===========================================================================
 *
 *       Filename:  huffman_tree.c
 *
 *    Description: Write a function that builds the Huffman tree
 *
 *        Version:  1.0
 *        Created:  20.12.2024 13:54:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Lévêque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ===========================================================================
 */

#include "huffman.h"

/**
 * huffman_tree - builds the Huffman tree
 * @data: array of characters
 * @freq: array of freqs
 * @size: size of the arrays data and freq
 *
 * Return: ptr to the root of the huffman tree, NULL otherwise
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root;
	heap_t *heap;

	if (!data || !freq || size <= 0)
		return (NULL);

	heap = huffman_priority_queue(data, freq, size);
	if (!heap)
		return (NULL);
	while (heap->root->left || heap->root->right)
		if (!huffman_extract_and_insert(heap))
		{
			heap_delete(heap, NULL);
			return (NULL);
		}

	root = (binary_tree_node_t *)heap->root->data;
	heap_delete(heap, NULL);
	return (root);
}
