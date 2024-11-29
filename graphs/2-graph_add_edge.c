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

/**
 * edge_exists - get of the edge already exists
 * @v_src: vertex source
 * @v_dest: vertex_dest
 *
 * Return: 1 if exists, 0 if not
 */
int edge_exists(vertex_t *v_src, vertex_t *v_dest)
{
	edge_t *edge = v_src->edges;
	while (edge)
	{
		if (edge->dest == v_dest)
			return (1);
		edge = edge->next;
	}
	return (0);
}

/**
 * create_and_place_edge - create a new edge and place it correctly
 * @v_src: vertex source
 * @v_dest: vertex destination
 *
 * Return: 1 on success, 0 on failure
 */
int create_and_place_edge(vertex_t *v_src, vertex_t *v_dest)
{
	edge_t *temp = v_src->edges, *new = NULL;

	while (temp && temp->next)
		temp = temp->next;
	
	new = malloc(sizeof(edge_t));
	if (!new) /* uh oh */
		return (0);
	new->dest = v_dest;
	new->next = NULL;
	if (!temp || v_src->nb_edges == 0)
		v_src->edges = new;
	else
		temp->next = new;

	return (1);
}

/**
 * graph_add_edge - add the new edge
 * @graph: graph
 * @src: source
 * @dest: destination
 * @type: edge type
 *
 * Return: 1 on success, 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	int return_code = 1;
	vertex_t *v_src, *v_dest;

	if (!graph)
		return (0);

	v_src = find_vertex(graph, src);
	v_dest = find_vertex(graph, dest);
	if (!v_src || !v_dest)
		return (0);

	/* create the 'main' edge */
	if (!edge_exists(v_src, v_dest))
	{
		if (!create_and_place_edge(v_src, v_dest))
			return_code = 0;
		else
			v_src->nb_edges++;
	}
	/* if it's a BIDIRECTIONAL type, create the 'second' edge */
	/* same logic as the 'main', but reverse src and dest */
	if (type == BIDIRECTIONAL && !edge_exists(v_dest, v_src))
	{	
		if (!create_and_place_edge(v_dest, v_src))
			return_code = 0;
		else
			v_dest->nb_edges++;
	}

	return (return_code);
}
