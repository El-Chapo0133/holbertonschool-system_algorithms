#ifndef HUFFMAN_H
#define HUFFMAN_H

#define SUCCESS 1
#define FAILURE 0

#include "heap/heap.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;

/*  CORE  */
symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);

/*  UTILS  */
void free_data(void *data);
int huffman_data_comparison(void *data1, void *data2);
void free_whole_binary_tree(binary_tree_node_t *root);

#endif
