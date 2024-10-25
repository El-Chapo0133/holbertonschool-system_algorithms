#include "3-array_to_rb_tree.h"


/**
 * array_to_rb_tree - create a rb tree from an array
 * @array: array to create the tree with
 * @size: size of the array
 *
 * Return: root of the newly rb tree
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;
	size_t index;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		if (rb_tree_insert(&root, array[index]) == NULL)
			if (!is_duplicate(array, size, array[index]))
				return (NULL);

	return (root);
}

/**
 * is_duplicate - check if a value is duplicated in the given array
 * @array: array of values
 * @size: size of the array
 * @value: value to look
 *
 * Return: 1 if duplicated, 0 otherwise
 */
int is_duplicate(int *array, size_t size, int value)
{
	size_t index;

	for (index = 0; index < size; index++)
		if (array[index] == value)
			return (true);
	return (false);
}
