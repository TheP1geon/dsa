#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/bstree.h"

TreeNode* tree_node_new(int data, TreeNode* left, TreeNode* right) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

TreeNode* tree_root_new(int data) {
    return tree_node_new(data, NULL, NULL);
}

void tree_node_free(TreeNode* node) {
    assert(node);
    if (node->left) {
        tree_node_free(node->left);
    }

    if (node->right) {
        tree_node_free(node->right);
    }

    free(node);
}

void tree_insert(TreeNode** root, int data) {
    if (!*root) {
        *root = tree_node_new(data, NULL, NULL);
        return;
    }

    if (data < (*root)->data) {
        tree_insert(&((*root)->left), data);
    } else {
        tree_insert(&((*root)->right), data);
    }
}

int tree_search(TreeNode* root, int needle) {
    if (!root) {
        return 0;
    }

    if (root->data == needle) {
        return 1;
    }

    return tree_search(root->left, needle) || tree_search(root->right, needle);
}

static void tree_print__(TreeNode* root, char sym, int tabs) {
    if (!root) {
        return;
    }

    for (int i = 0; i < tabs; ++i) {
        printf("  ");
    }
    printf("|%c %d\n", sym, root->data);

    if (root->right) {
        tree_print__(root->right, '~', tabs+1);
    }
    if (root->left) {
        tree_print__(root->left, '-', tabs+1);
    }
}

void tree_print(TreeNode* root) {
    tree_print__(root, '-', 0);
}

