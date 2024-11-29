#include "graphs.h"


/**
 * graph_create - create a new graph_t
 *
 * Return: the newly created graph
 */
graph_t *graph_create(void)
{
	graph_t *new = malloc(sizeof(graph_t));

	if (!new)
		return (NULL);

	new->nb_vertices = 0;
	new->vertices = NULL;

	return (new);
}
