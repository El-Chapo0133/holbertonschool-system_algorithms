/*
 * ===========================================================================
 *
 *       Filename:  huffman_priority_queue.c
 *
 *    Description: Write a function that creates a priority queue for
 *			the Huffman coding algorithm
 *
 *        Version:  1.0
 *        Created:  20.12.2024 10:07:56
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
 * free_data - delete a binary_tree_node_t
 * @data: void ptr to a binary_tree_node_t to delete
 *
 * Return: void
 */
void free_data(void *data)
{
	binary_tree_node_t *node = (binary_tree_node_t *)data;

	if (!node)
		return;
	if (node->data)
	{
		free(node->data);
		fprintf(stderr, "%ls\n", (int *)node->data);
	}
	free(node);
}

/**
 * huffman_data_comparison - get the sub of data1 and data2
 * @data1: void ptr to node1
 * @data2: void ptr to node2
 *
 * Return: sub of data1 and data2
 */
int huffman_data_comparison(void *data1, void *data2)
{
	size_t freq_1 = 0, freq_2 = 0;
	binary_tree_node_t *data_node1 = NULL, *data_node2 = NULL;

	data_node1 = (binary_tree_node_t *) data1;
	data_node2 = (binary_tree_node_t *) data2;

	/* when data1 doesn't exists return -1 */
	if ((!data_node1 && data_node2) ||
		(data_node1 && !data_node1->data && data_node2 && data_node2->data))
		return (-1);
	/* when data2 doesn't exists return 1 */
	else if ((data_node1 && !data_node2) ||
		(data_node1 && data_node1->data && data_node2 && !data_node2->data))
		return (1);
	/* when none exists return 0 */
	else if ((!data_node1 && !data_node2) ||
		(data_node1 && !data_node1->data && data_node2 && !data_node2->data))
		return (0);

	/* else return the sub */
	freq_1 = ((symbol_t *)data_node1->data)->freq;
	freq_2 = ((symbol_t *)data_node2->data)->freq;

	return (freq_1 - freq_2);
}

/**
 * huffman_priority_queue - creates a priority queue for
 * the Huffman coding algorithm
 * @data: array of characters
 * @freq: array of freqs
 * @size: size of the arrays data and freq
 *
 * Return: newly created heap
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t iterator;
	symbol_t *new_symbol = NULL;
	heap_t *heap = NULL;
	binary_tree_node_t *new_node, *temp;

	if (!data || !freq)
		return (NULL);

	heap = heap_create(huffman_data_comparison);
	if (!heap)
		return (NULL);

	/* for each characters, create or add the symbol */
	for (iterator = 0; iterator < size; iterator++)
	{
		new_symbol = symbol_create(data[iterator], freq[iterator]);
		if (!new_symbol)
		{
			heap_delete(heap, free_data);
			return (NULL);
		}

		new_node = binary_tree_node(NULL, new_symbol);
		if (!new_node)
		{
			free(new_symbol);
			heap_delete(heap, free_data);
			return (NULL);
		}

		temp = heap_insert(heap, (void *)new_node);
		if (!temp)
		{
			free_data(new_node);
			free(new_symbol);
			heap_delete(heap, free_data);
			return (NULL);
		}
	}
	return (heap);
}
