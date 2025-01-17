
#ifndef H_PATHFINDING
#define H_PATHFINDING

#include "graphs.h"
#include "queues.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 2147483647

/**
 * euclidean_dist - get euclidian distance between two points
 * https://en.wikipedia.org/wiki/Euclidean_distance
 * @x1: first point x
 * @y1: first point y
 * @x2: second point x
 * @y2: second point y
 *
 * Return: euclidean result
 */
#define euclidean_dist(x1, y1, x2, y2) sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))


/**
 * struct dijkstra_queue_s - dijkstra queue
 * @dq_source: ptr to dijkstra source queue node
 * @dest: ptr to dest vertex node
 * @weigth: weight of the cell
 * @next: ptr to next vertex node
 */
typedef struct dijkstra_queue_s
{
	struct dijkstra_queue_s *dq_source;
	vertex_t *dest;
	int weight;
	struct dijkstra_queue_s *next;
} dijkstra_queue_t;

/**
 * enum cardinal_dir - cardinal directions
 * @EAST: east
 * @SOUTH: south
 * @WEST: west
 * @NORTH: north
 * @SIZE: array size
 */
enum cardinal_dir
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
	SIZE
};

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/* Main functions */
queue_t *backtracking_array(char **map, int rows, int cols,
				point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
				vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
				vertex_t const *target);
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
				vertex_t const *target);

#endif
