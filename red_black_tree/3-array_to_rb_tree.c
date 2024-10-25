#include "3-array_to_rb_tree.h"


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

int is_duplicate(int *array, size_t size, int value)
{
	size_t index;
	for (index = 0; index < size; index++)
		if (array[index] == value)
			return (true);
	return (false);
}
