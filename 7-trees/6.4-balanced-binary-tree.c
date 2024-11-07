// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) (a > b ? a : b)

int helper(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = helper(root->left);
    int rightDepth = helper(root->right);

    // If it's not balanced
    if (leftDepth == -1 || rightDepth == -1) {
        return - 1;
    }

    // Determine if it's balanced
    if (abs(leftDepth - rightDepth) > 1) {
        return -1;
    }

    return 1 + MAX(leftDepth, rightDepth);
}

bool isBalanced(struct TreeNode* root) {
    return helper(root) != -1;
}
// @leet end
