/*
 * ==========================================================================
 *
 *       Filename:  2-dijkstra_graph.c
 *
 *    Description:  Write a function that searches for the shortest path
 *			from a starting point to a target point in a graph
 *
 *        Version:  1.0
 *        Created:  17.01.2025 09:56:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */

#include "pathfinding.h"


int get_lowest_edge(vertex_t const *vertex)
{
	int lowest = INT_MAX;
	edge_t *edge = vertex->edges;

	if (!vertex || !edge)
		return (-1);
	while (edge)
		if (edge->weight < lowest)
			lowest = edge->weight;

	return (lowest);
}

void discover_dijkstra(vertex_t const *current,
		int *locker, int weight)
{
	edge_t *edge;
	int lowest;

	if (!current || !locker)
		return;

	lowest = get_lowest_edge(current);
	if (lowest == -1)
		return;
	
	edge = current->edges;
	while (edge)
	{
		if (edge->weight == lowest)
		{
			fprintf(stdout, "Checking %s, distance from %s is %i\n",
					edge->dest, current->content,
					edge->weight + weight);
			edge->weight += weight;
			locker[edge->dest->index] = 1;
		}
		
		
		edge = edge->next;
	}
}

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *queue;
	int *locker;

	if (!graph || !start || !target)
		return (NULL);

	queue = queue_create();
	if (!queue)
		return (NULL);
	locker = calloc(graph->nb_vertices, sizeof(locker));
	if (!locker)
		return (NULL);
	locker[start->index] = 1;

	discover_dijkstra(start, locker, 0);


	return (queue);
}
