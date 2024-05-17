#include "include/bstree.h"

int main(void) {
    TreeNode* root = tree_root_new(3);
    tree_insert(&root, 2);
    tree_insert(&root, 10);
    tree_insert(&root, 132);
    tree_insert(&root, 1);
    tree_insert(&root, 19);
    tree_insert(&root, 6);
    tree_print(root);

    tree_node_free(root);
    return 0;
}
