#ifndef __TREE_H
#define __TREE_H

typedef struct TreeNode TreeNode;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* tree_node_new(int data, TreeNode* left, TreeNode* right);
TreeNode* tree_root_new(int data);
void tree_node_free(TreeNode* node);
void tree_insert(TreeNode** root, int data);
int tree_search(TreeNode* root, int needle);
void tree_print(TreeNode* root);

#endif  //__TREE_H
