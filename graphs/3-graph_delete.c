#include "graphs.h"

void graph_delete(graph_t *graph)
{
	vertex_t *vertex;
	edge_t *edge;

	if (!graph)
		return;

	while (graph->vertices)
	{
		vertex = graph_vertices
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
