#ifndef RB_TREE_INSERT
#define RB_TREE_INSERT

rb_tree_t *rb_tree_get_uncle(rb_tree_t *n);
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree);
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree);
rb_tree_t *rb_tree_insert_case4(rb_tree_t *node);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *rb_tree_insert_recurse(rb_tree_t *tree, int value);
rb_tree_t *rb_tree_insert_repair(rb_tree_t *root, rb_tree_t *node);


#endif
