// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>

// I love trees, this took me literally 4 minutes.
// First time ever I do a leetcode problem this fast in C
struct TreeNode* invertTree(struct TreeNode* root) {
    // First base case?
    if (root == NULL) {
        return root;
    }

    invertTree(root->left);
    invertTree(root->right);

    // Invert the children
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}
// @leet end
