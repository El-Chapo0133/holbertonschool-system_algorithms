#include "graphs.h"



/**
 * graph_add_vertex - create a new vertex
 * @graph: graph
 * @str: vertex str
 *
 * Return: newly created vertex
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = NULL, *temp = NULL;

	if (!str || !graph)
		return (NULL);
	temp = graph->vertices;
	while (temp && temp->next)
	{
		if (!strcmp(temp->content, str))
			return (NULL);
		temp = temp->next;
	}

	vertex = malloc(sizeof(vertex_t));
	if (!vertex) /* uh oh*/
		return (NULL);

	vertex->content = strdup(str); /* important */
	vertex->index = 0;
	vertex->edges = NULL;
	vertex->nb_edges = 0;
	vertex->next = NULL;

	if (!temp)
		graph->vertices = vertex;
	else
	{
		vertex->index = temp->index + 1;
		temp->next = vertex;
	}

	graph->nb_vertices++;
	return (vertex);
}
