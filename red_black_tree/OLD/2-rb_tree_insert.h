#ifndef RB_TREE_INSERT
#define RB_TREE_INSERT

#include "rb_trees.h"

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *insert_at_right_place(rb_tree_t **tree, int value);
void rotate_left(rb_tree_t **tree, rb_tree_t *parent);
void rotate_right(rb_tree_t **tree, rb_tree_t *grand_parent);
void rotate_cases(rb_tree_t **tree, rb_tree_t **new_node, rb_tree_t *parent,
		rb_tree_t *grand_parent, int is_right);
void repear_rb_tree(rb_tree_t **tree, rb_tree_t *new_node);
void swap_colors(rb_tree_t *node1, rb_tree_t *node2);

#endif
