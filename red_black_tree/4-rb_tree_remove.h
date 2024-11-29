#ifndef RB_TREE_REMOVE
#define RB_TREE_REMOVE


rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);
void repear_deletion(rb_tree_t **root, rb_tree_t *to_fix);
rb_tree_t *find_smallest(rb_tree_t *root);
void transplant(rb_tree_t **root, rb_tree_t *to_remove, rb_tree_t *child);
rb_tree_t *find_node_to_remove(rb_tree_t *root, int n);
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree);
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree);


#endif
