/*
 * ==========================================================================
 *
 *       Filename:  1-backtracking_graph.c
 *
 *    Description:  Write a function that searches for the first path from a
 *			starting point to a target point in a graph
 *
 *        Version:  1.0
 *        Created:  10.01.2025 15:50:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "pathfinding.h"


queue_node_t *dfs_graph(queue_t *queue, int *visited, const vertex_t *current,
		char *target)
{
	edge_t *edge;

	if (!current || visited[current->index] == 1)
		return (NULL);

	fprintf(stdout, "Checking %s\n", current->content);
	if (!strcmp(current->content, target->content))
		return (queue_push_front(queue, strdup(current->content)));

	visited[current->index] = 1;

	edge = current->edges;
	while (edge)
	{
		if (dfs(queue, visited, edge->dest, target))
			return (queue_push_front(queue, strdup(current->content)));
		edge = edge->next;
	}

	return (NULL);
}

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *queue;
	int *visited;

	if (!graph || !start || !target)
		return (NULL);

	queue = queue_create();
	if (!queue)
		return (NULL);
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (NULL);

	/* setbuf(stdout, NULL);
	if (!dfs(queue, visited, start, target->content))
	{
		queue_delete(queue);
		queue = NULL;
	}*/
	free(visited);
	return (queue);
}
