/*
 * ==========================================================================
 *
 *       Filename:  0-backtracking_array.c
 *
 *    Description: Write a function that searches for the first path from a
 *	starting point to a target point within a two-dimensional array
 *
 *        Version:  1.0
 *        Created:  10.01.2025 09:45:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#include "pathfinding.h"

/**
 * free_visited - free the viststed 2D array
 * @visited: array to free
 * @size: array size
 *
 * Return: void
 */
void free_visited(int **visited, int size)
{
	while (size)
		free(visited[--size]);
	free(visited);
}

/**
 * push_point_to_queue - create a new point_t and call push_queue_front
 * @queue: queue to push_front
 * @x: position x
 * @y: position y
 *
 * Return: 0 on success 1 on failure
 */
int push_point_to_queue(queue_t *queue, int x, int y)
{
	point_t *point = malloc(sizeof(point_t));

	if (!point)
		return (1);
	point->x = x;
	point->y = y;
	if (!queue_push_front(queue, point))
		return (1);
	return (0);
}

/**
 * find_path - recursivly try to find path
 * @map: map
 * @rows: map rows
 * @cols: map cols
 * @queue: queue
 * @visited: visited array
 * @directions: additions to directions
 * @target: target point_t
 * @current_x: current x position
 * @current_y: current y position
 *
 * Return: 0 on success 1 on failure
 */
int find_path(char **map, int rows, int cols,
		queue_t *queue, int **visited, point_t *directions,
		point_t const *target, int current_x, int current_y)
{
	int index;

	if (current_x < 0 || current_x >= cols ||
			current_y < 0 || current_y >= rows ||
			map[current_y][current_x] == '1' ||
			visited[current_y][current_x] == 1)
		return (1);

	fprintf(stdout, "Checking coordinates [%i, %i]\n",
			current_x, current_y);
	if (current_x == target->x && current_y == target->y)
		return (push_point_to_queue(queue, current_x, current_y));
	visited[current_y][current_x] = 1;
	for (index = 0; index < SIZE; index++)
	{
		if (find_path(map, rows, cols, queue,
				visited, directions, target,
				current_x + directions[index].x,
				current_y + directions[index].y) == 0)
			return (push_point_to_queue(queue,
						current_x, current_y));
	}
	return (1);
}

/**
 * initialize_all - init queue, direction and visited variables
 * @queue: ptr to queue to init
 * @directions: ptr to point_t to init
 * @visited: ptr to visited to init
 * @rows: rows number of the map
 * @cold: colds number of the map
 *
 * Return: 0 on success 1 on error
 */
int initialize_all(queue_t **queue, point_t *directions, int ***visited,
		int rows, int cols)
{
	int index;

	/* queue init */
	*queue = queue_create();
	if (!queue)
		return (1);

	/* direction init */
	directions[EAST].x = 1, directions[EAST].y = 0;
	directions[SOUTH].x = 0, directions[SOUTH].y = 1;
	directions[WEST].x = -1, directions[WEST].y = 0;
	directions[NORTH].x = 0, directions[NORTH].y = -1;

	/* visited array init */
	*visited = malloc(rows * sizeof(**visited));
	if (*visited == NULL)
		return (1);
	for (index = 0; index < rows; index++)
	{
		(*visited)[index] = calloc(cols, sizeof(***visited));
		if ((*visited)[index] == NULL)
			return (1);
	}

	return (0);
}

/**
 * backtracking_array - searches for the first path from a starting point
 * to a target point within a two-dimensional array
 * @map: array of the map
 * @rows: rows of the map
 * @cols: cols of the map
 * @start: starting point_t
 * @target: target point_t
 *
 * Return: a queue with each nodes
 */
queue_t *backtracking_array(char **map, int rows, int cols,
		point_t const *start, point_t const *target)
{
	queue_t *queue;
	point_t directions[SIZE];
	int **visited;

	if (!map || !start || !target || rows < 1 || cols < 1)
		return (NULL);
	if (initialize_all(&queue, directions, &visited, rows, cols) == 1)
		return (NULL);

	setbuf(stdout, NULL);
	if (find_path(map, rows, cols, queue, visited, directions, target,
				start->x, start->y) == 1)
	{
		queue_delete(queue);
		return (NULL);
	}

	free_visited(visited, rows);
	return (queue);
}
