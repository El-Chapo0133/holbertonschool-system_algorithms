#include "graphs.h"

/**
 * create_queue - create a queue_t
 *
 * Return: newly created queue_t
 */
queue_t *create_queue()
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (!queue) /* uh oh */
		return (NULL);

	queue->rear = -1;
	queue->front = -1;

	return (queue);
}

/**
 * enqueue - enqueue an item to the given queue
 * @queue: queue to enqueue to
 * @value: value to enqueue
 *
 * Return: void
 */
void enqueue(queue_t *queue, int value)
{
	if (queue->rear == (QUEUE_MAX_SIZE - 1))
	{
		printf("Queue is currently full 2^16 items reached\n");
		return;
	}

	if (queue->front == -1)
		queue->front = 0;
	queue->rear++;
	queue->items[queue->rear] = value;
}

/**
 * dequeue - dequeue an item from the given queue
 * @queue: queue to dequeue from
 * @peek: if peek is true, only peek the item
 *
 * Return: the dequeued item
 */
int dequeue(queue_t *queue, int peek)
{
	int item;

	if (queue->rear == -1)
	{
		printf("Queue is currently empty\n");
		return (-1);
	}
	item = queue->items[queue->front];
	if (peek)
		return (item);
	queue->front++;
	if (queue->front > queue->rear)
		queue->front = queue->rear = -1;

	return (item);
}

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
 * breadth_first_traverse - BFS algorithm throught graph
 * @graph: graph
 * @action: action to do for each unvisited vertice
 *
 * Return: result depth
 */
size_t breadth_first_traverse(const graph_t *graph,
		void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth = 0;
	size_t *visited;
	int index = 0;
	vertex_t *current, *dest;
	edge_t *edge;
	queue_t *queue;

	if (!graph || graph->nb_vertices == 0 || graph->vertices == NULL)
		return (0);
	visited = calloc(sizeof(size_t), graph->nb_vertices);
	queue = create_queue(), current = graph->vertices;
	enqueue(queue, current->index), enqueue(queue, LEVEL_BREAKER);
	while (queue->rear != -1) /* loop until queue is empty */
	{
		index = dequeue(queue, 0);
		if (index == LEVEL_BREAKER) /* check if it's a LEVEL_BREAKER item */
		{
			enqueue(queue, LEVEL_BREAKER);
			if (dequeue(queue, 1) == LEVEL_BREAKER)
				break;
			depth++;
			continue;
		}

		current = get_vertex_by_index(graph, index);
		if (visited[current->index] == UNVISITED)
		{
			visited[current->index] = VISITED;
			action(current, depth), edge = current->edges;
			while (edge)
			{
				dest = edge->dest;
				if (dest && visited[dest->index] == UNVISITED)
					enqueue(queue, dest->index);
				edge = edge->next;
			}
		}
	}
	free(queue), free(visited);
	return (depth == 0 ? 0 : depth - 1);
}
