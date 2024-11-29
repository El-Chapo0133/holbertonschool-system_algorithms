#include "graphs.h"


vertex_t *get_vertex_by_index(const graph_t *graph, size_t index)
{
	vertex_t *temp = graph->vertices;

	if (index > graph->nb_vertices)
		return (NULL);
	while (temp)
	{
		if (temp->index == index)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void dfs(int index, size_t *stack, size_t current_depth,
		size_t *depth, const graph_t *graph,
		void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *v_temp, *v_dest;
	edge_t *edge;

	v_temp = get_vertex_by_index(graph, index);
	if (!v_temp || stack[index] == VISITED)
		return;
	
	action(v_temp, current_depth);
	if (current_depth > *depth)
		*depth = current_depth;
	stack[index] = VISITED;
	edge = v_temp->edges;
	
	while (edge)
	{
		v_dest = edge->dest;
		if (stack[v_dest->index] == UNVISITED)
			dfs(v_dest->index, stack, current_depth, depth, graph, action);
		edge = edge->next;
	}
}

size_t depth_first_traverse(const graph_t *graph,
		void (*action)(const vertex_t *v,
		size_t depth))
{
	size_t depth = 0;
	size_t *stack;
	vertex_t *temp;

	if (!graph)
		return (0);

	stack = malloc(sizeof(size_t) * graph->nb_vertices);
	if (!visited) /* uh oh */
		return (0);
	
	temp = graph->vertices;
	if (!temp)
		return (0);

	while (temp)
	{
		if (stack[temp->index] == UNVISITED)
			dfs(temp->index, stack, 0, &depth, graph, action);
		temp = temp->next;
	}

	free(visited);
	return (depth);
}