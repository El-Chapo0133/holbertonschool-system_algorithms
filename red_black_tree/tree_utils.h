#ifndef RB_TREE_UTILS
#define RB_TREE_UTILS

#include "rb_trees.h"

void swap_colors(rb_tree_t *node1, rb_tree_t *node2);
rb_tree_t *get_uncle(const rb_tree_t *tree);

#endif
