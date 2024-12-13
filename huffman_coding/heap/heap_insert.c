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
 * swap - swap the data of two given nodes
 * @a: first node
 * @b: second node
 *
 * Return: void
 */
void swap(binary_tree_node_t *a, binary_tree_node_t *b)
{
	void *temp = a->data;

	a->data = b->data;
	b->data = temp;
}

/**
 * heapify - swap the values until the tree is min-heap-ed
 * @heap: heap of the tree
 * @node: node to check from
 *
 * Return: void
 */
void heapify(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *temp = node;

	if (!heap || !node)
		return;
	/* swap the values until tree is min-heap or root is reached */
	while (temp->parent)
	{
		/* if this node has a smaller value than his parent */
		if (heap->data_cmp(temp->data, temp->parent->data) < 0)
			swap(temp, temp->parent);
		else /* if no swap is needed it means the tree is min-heap */
			break;
		temp = temp->parent;
	}
}

/**
 * get_binary_depth - get the depth of the given binary heap
 * @size: number of nodes in the tree
 *
 * Return: depth of the tree
 */
int get_binary_depth(long size)
{
	long num_nodes = 1, depth = 0;

	/* magical code i found on stackoverflow */
	while (size >= num_nodes)
		num_nodes += (1 << (depth++ + 1));
	return (depth);
}

/**
 * try_to_insert - try to insert the new node in the binary heap
 * @root: root node
 * @node: node to insert
 * @deep: current depth
 * @depth_target: target depth
 *
 * Return: 1 if inserted, 0 otherwise
 */
int try_to_insert(binary_tree_node_t *root, binary_tree_node_t *node,
		long deep, long depth_target)
{
	int left = 0, right = 0;

	/* if target depth is reached, try to insert it */
	/* if both branch are used, return 0 */
	if (deep == depth_target)
	{
		if (!root->left)
			root->left = node;
		else if (!root->right)
			root->right = node;
		else
			return (0);
		node->parent = root;
		return (1);
	}

	left = try_to_insert(root->left, node, deep + 1, depth_target);
	if (left)
		return (1);
	right = try_to_insert(root->right, node, deep + 1, depth_target);
	if (right)
		return (1);
	return (0);
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

	/* when the root is unset */
	if (!heap->root)
	{
		heap->size++;
		heap->root = node;
		return (node);
	}

	is_inserted = try_to_insert(heap->root, node, 0,
			get_binary_depth(heap->size) - 1);

	if (!is_inserted)
	{
		free(node);
		return (NULL);
	}
	/* min-heap-ify the tree */
	heapify(heap, node);

	heap->size++;
	return (node);
}
