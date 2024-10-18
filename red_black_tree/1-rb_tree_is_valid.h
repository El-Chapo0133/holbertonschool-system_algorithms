#ifndef RB_TREE_IS_VALID
#define RB_TREE_IS_VALID

int check_height(const rb_tree_t *tree);
int check_bst(const rb_tree_t *tree);
int recursive_bst_check(const rb_tree_t *tree, int min, int max);

#endif
