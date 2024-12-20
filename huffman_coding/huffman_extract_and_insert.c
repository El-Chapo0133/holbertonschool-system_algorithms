/*
 * ===========================================================================
 *
 *       Filename:  huffman_extract_and_insert.c
 *
 *    Description: Write a function that extracts the two nodes of the
 *		priority queue and insert a new one
 *
 *        Version:  1.0
 *        Created:  20.12.2024 10:22:44
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
 * huffman_extract_and_insert - extracts the two min nodes of the
 * priority queue and insert a new one
 * @priority_queue: pointer to the priority queue to extract from
 *
 * Return: 1 on success 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	void *node_ptr1, *node_ptr2;
	binary_tree_node_t *new_node, *node1, *node2;
	symbol_t *new_symbol, *symbol1, *symbol2;

	node_ptr1 = heap_extract(priority_queue);
	node_ptr2 = heap_extract(priority_queue);
	if (!node_ptr1 || !node_ptr2)
		return (FAILURE);

	node1 = (binary_tree_node_t *)node_ptr1;
	node2 = (binary_tree_node_t *)node_ptr2;
	symbol1 = (symbol_t *)node1->data;
	symbol2 = (symbol_t *)node2->data;

	new_symbol = symbol_create(-1, symbol1->freq + symbol2->freq);
	if (!new_symbol)
		return (FAILURE);

	new_node = binary_tree_node(NULL, new_symbol);
	new_node->left = node1;
	new_node->right = node2;
	node1->parent = new_node;
	node2->parent = new_node;

	if (!heap_insert(priority_queue, new_node))
		return (FAILURE);
	return (SUCCESS);
}
