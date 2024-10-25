#include "rb_trees.h"

int main(void)
{
	rb_tree_t *root = NULL;
	rb_tree_t *node = NULL;

	node = rb_tree_insert(&root, 98);
	node = rb_tree_insert(&root, 33);
	node = rb_tree_insert(&root, 402);
	printf("Inserted %d", node->n);
}
