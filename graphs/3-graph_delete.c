#include "graphs.h"


/**
 * graph_delete - delete the graph, all it's vertices
 * and all it's edges
 * @graph: graph
 *
 * Return: void
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex;
	edge_t *edge;

	if (!graph)
		return;

	while (graph->vertices)
	{
		vertex = graph->vertices;
		while (vertex->edges)
		{
			edge = vertex->edges;
			vertex->edges = edge->next;
			free(edge);
		}
		graph->vertices = vertex->next;
		free(vertex->content);
		free(vertex);
	}
	free(graph);
	graph = NULL;
}
