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

#define MAX(a,b) (a > b ? a : b)

// I'm so good, 2 problems in less than 7 minutes
// New record
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = 1 + maxDepth(root->left);
    int rightHeight = 1 + maxDepth(root->right);

    return MAX(leftHeight, rightHeight);
}
// @leet end
