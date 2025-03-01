#include "rb_trees.h"
#include "2-rb_tree_insert.h"

void rb_tree_print(const rb_tree_t *tree);

int main(void)
{
	rb_tree_t *root = NULL, *node;

    node = rb_tree_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 512);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    node = rb_tree_insert(&root, 624);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 780);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
}
