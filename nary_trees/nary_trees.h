/*
 * ==========================================================================
 *
 *       Filename:  nary.h
 *
 *    Description:  header file for the nary_tree project
 *
 *        Version:  1.0
 *        Created:  21.02.2025 15:00:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  Holberton
 *
 * ==========================================================================
 */

#ifndef H_NARY
#define H_NARY

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct nary_tree_s - N-ary tree node structure
 *
 * @content: Content of the node
 * @parent: Pointer to the parent node
 * @nb_children: Number of children
 * @children: Pointer to the head node of the children linked list
 * @next: Pointer to the next child in the parent's children linked list
 */
typedef struct nary_tree_s
{
    char            *content;
    struct nary_tree_s  *parent;
    size_t          nb_children;
    struct nary_tree_s  *children;
    struct nary_tree_s  *next;
} nary_tree_t;

nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str);
void nary_tree_delete(nary_tree_t *tree);
size_t nary_tree_traverse(nary_tree_t const *root,
					void (*action)(nary_tree_t const *node, size_t depth));
size_t nary_tree_search(nary_tree_t const *root,
					void (*action)(nary_tree_t const *node, size_t depth),
								size_t _depth);
size_t nary_tree_diameter(nary_tree_t const *root);
size_t find_diameter(nary_tree_t const *root, size_t depth, size_t *diameter);
int path_exists(nary_tree_t const *root, char const * const *path);
int check_path(nary_tree_t const *root, char const * const *path, size_t pidx);


#endif
