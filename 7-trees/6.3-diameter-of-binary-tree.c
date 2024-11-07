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

// Count the edges for a node and return the longest path (left or right)
int edges(struct TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;
    }

    int leftEdges = edges(root->left, diameter);
    int rightEdges = edges(root->right, diameter);

    int currentDiameter = leftEdges + rightEdges;

    *diameter = MAX(currentDiameter, *diameter);

    return 1 + MAX(leftEdges, rightEdges);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    edges(root, &diameter);

    return diameter;
}
// @leet end
