/*
 * ===========================================================================
 *
 *       Filename:  huffman_codes.c
 *
 *    Description: Write a function that build the Huffman tree and print
 *			the resulting Huffman codes for each symbol
 *
 *        Version:  1.0
 *        Created:  20.12.2024 15:45:33
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
 * free_whole_binary_tree - recursivly free the whole tree
 * @root: root node
 *
 * Return: void
 */
void free_whole_binary_tree(binary_tree_node_t *root)
{
	if (root->left)
		free_whole_binary_tree(root->left);
	if (root->right)
		free_whole_binary_tree(root->right);
	free(root->data);
	free(root);
}

/**
 * get_huffman_depth - recursivly get the depth of the binary tree
 * @root: binary tree root
 * @current_depth: current depth
 *
 * Return: depth of the binary tree
 */
size_t get_huffman_depth(binary_tree_node_t *root, size_t current_depth)
{
	int left_depth = -1, right_depth = -1;

	if (root->left)
		left_depth = get_huffman_depth(root->left, current_depth + 1);
	if (root->right)
		right_depth = get_huffman_depth(root->right, current_depth + 1);
	else
		return (current_depth);

	if (left_depth > right_depth)
		return (left_depth);
	return (right_depth);
}

/**
 * print_huffman_tree - recursivly print the huffman tree
 * @root: tree root
 * @code: codes
 * @depth: current depth
 *
 * Return: void
 */
void print_huffman_tree(binary_tree_node_t *root, char *code, size_t depth)
{
	symbol_t *symbol;

	/* when left exists, print a '0' */
	if (root->left)
	{
		code[depth] = '0';
		print_huffman_tree(root->left, code, depth + 1);
	}
	/* when right exists print a '1' */
	if (root->right)
	{
		code[depth] = '1';
		print_huffman_tree(root->right, code, depth + 1);
	}
	/* then print the symbol and the code */
	else
	{
		symbol = (symbol_t *)root->data;
		fprintf(stdout, "%c: %s\n", symbol->data, code);
	}
}

/**
 * huffman_codes - build the Huffman tree and print the resulting
 * Huffman codes for each symbol
 * @data: array of characters
 * @freq: array of freqs
 * @size: size of the arrays data and freq
 *
 * Return: 1 on success 0 on failure
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root;
	char *code;
	size_t depth, index;

	root = huffman_tree(data, freq, size);
	if (!root)
		return (FAILURE);

	depth = get_huffman_depth(root, 0);
	code = calloc(sizeof(char), depth);

	print_huffman_tree(root, code, 0);

	free(code);
	free_whole_binary_tree(root);
	return (SUCCESS);
}
