#include "heap.h"


/**
 * heap_create - create a heap_t
 * @data_cmd: ptr to cmp function
 *
 * Return: newly created heap_t
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = malloc(sizeof(heap_t));

	if (!heap)
		return (NULL);
	heap->size = 0;
	heap->root = NULL;
	heap->data_cmp = data_cmp;
	return (heap);
}
