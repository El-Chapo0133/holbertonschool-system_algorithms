#include "graphs.h"

/**
 * find_vertex - find the vertex in the given graph
 * from the given str
 * @graph: graph
 * @str: str to find
 *
 * Return: found vertex or NULL
 */
vertex_t *find_vertex(graph_t *graph, const char *str)
{
	vertex_t *temp;

	if (!str)
		return (NULL);
	temp = graph->vertices;
	while (temp)
	{
		if (strcmp(temp->content, str))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
