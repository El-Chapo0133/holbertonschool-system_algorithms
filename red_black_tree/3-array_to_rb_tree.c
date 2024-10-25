#include "rb_trees.h"


rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;
	size_t index_i;

	if (array == NULL)
		return (NULL);

	for (index_i = 0; index_i < size; index_i++)
		if (rb_tree_insert(&root, array[index_i]) == NULL)
			return (NULL);

	return (root);
}
