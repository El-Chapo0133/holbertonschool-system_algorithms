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


queue_t *find_path(dijkstra_queue_t *dq)
{
	queue_t *queue;

	if (!dq)
		return (NULL);
	queue = queue_create();
	if (!queue)
		return (NULL);
	while (1)
	{
		if (!queue_push_front(queue, strdup(dq->dest->content)))
			return (NULL);
		if (dq == dq->dq_source)
			break;
		dq = dq->dq_source;
	}

	return (queue);
}

dijkstra_queue_t *create_dq_node(dijkstra_queue_t *dq, dijkstra_queue_t *src,
		edge_t *dest)
{
	dijkstra_queue_t *node = malloc(sizeof(dijkstra_queue_t));

	if (!node)
		return (NULL);
	node->dq_source = src;
	node->dest = dest->dest;
	node->weight = src->weight + dest->weight;
	node->next = NULL;

	if (dq->next != NULL)
		node->next = dq->next;
	dq->next = node;
	return (node);
}

dijkstra_queue_t *insert_dq_node(dijkstra_queue_t *head, dijkstra_queue_t *src,
		edge_t *dest, int *dest_added)
{
	dijkstra_queue_t *current, *delete, *temp, *new;

	if (!head)
		return (NULL);
	current = head;
	while (current->next &&
			src->weight + dest->weight > current->next->weight)
		if (dest->dest == current->next->dest)
			return (current->next);
	
	if (dest_added[dest->dest->index])
	{
		for (delete = current;
				delete->dest != dest->dest;
				temp = delete, delete = delete->next)
			;

		temp->next = delete->next;
		free(delete);
	}
	new = create_dq_node(current, src, dest);
	dest_added[new->dest->index] = 1;
	return (new);
}

dijkstra_queue_t *discover(dijkstra_queue_t *dq, vertex_t const *start,
		vertex_t const *target, int *visited, int *dest_added)
{
	dijkstra_queue_t *dq_current;
	edge_t *edge;

	if (!dq || !visited)
		return (NULL);

	for (dq_current = dq; dq_current != NULL; dq_current = dq_current->next)
	{
		fprintf(stdout, "Checking %s, distance from %s is %i\n",
				dq_current->dest->content, start->content,
				dq_current->weight);
		if (dq_current->dest == target)
			return (dq_current);

		edge = dq_current->dest->edges;
		while (edge)
		{
			if (!visited[edge->dest->index])
				if (!insert_dq_node(dq, dq_current, edge,
							dest_added))
					return (NULL);
			edge = edge->next;
		}
		visited[dq_current->dest->index] = 1;
	}
	return (NULL);
}

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
		vertex_t const *target)
{
	queue_t *queue;
	dijkstra_queue_t *dq = malloc(sizeof(dijkstra_queue_t)), *temp;
	int *visited, *dest_added;

	if (!graph || !start || !target || !dq)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(visited));
	if (!visited)
		return (NULL);
	dest_added = calloc(graph->nb_vertices, sizeof(dest_added));
	if (!dest_added)
		return (NULL);

	dq->dq_source = dq;
	dq->dest = (vertex_t *)start;
	dq->weight = 0;
	dq->next = NULL;
	queue = find_path(discover(dq, start, target, visited, dest_added));
	while (dq)
	{
		temp = dq;
		dq = dq->next;
		free(temp);
	}

	free(visited);
	free(dest_added);
	return (queue);
}
