#include "graphs.h"


/**
 * get_vertex_by_index - get the vertex by the given index
 * @graph: graph
 * @index: index to get
 *
 * Return: correct vertex otherwise NULL
 */
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

/**
 * dfs - dfs algorithm, recursivly fill the stack and explore the graph
 * @index: current index to look for
 * @stack: stack of visited/unvisited indexes
 * @current_depth: current depth of the recursive function
 * @depth: final depth
 * @graph: graph
 * @action: action to trigger on every visited vertice
 *
 * Return: void
 */
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
			dfs(v_dest->index, stack, current_depth + 1, depth, graph, action);
		edge = edge->next;
	}
}

/**
 * depth_first_traverse - a function that goes throught the graph using dfs
 * @graph: graph
 * @action: action to be trigger on every visited vertice
 *
 * Return: the max depth or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
		void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth = 0;
	size_t *stack;
	vertex_t *temp;

	if (!graph)
		return (0);

	/* allocate full array set at 0 */
	stack = calloc(sizeof(size_t), graph->nb_vertices);
	if (!stack) /* uh oh */
	{
		free(stack);
		return (0);
	}

	temp = graph->vertices;
	if (!temp) /* uh oh */
	{
		free(stack);
		return (0);
	}

	dfs(temp->index, stack, 0, &depth, graph, action);

	free(stack);
	return (depth);
}
