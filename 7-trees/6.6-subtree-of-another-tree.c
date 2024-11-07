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
#include <stdbool.h>

bool compareSubtrees(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root && !subRoot) {
        return true;
    } else if (!root || !subRoot) {
        return false;
    } else if (root->val != subRoot->val) {
        return false;
    }

    bool left = compareSubtrees(root->left, subRoot->left);
    bool right = compareSubtrees(root->right, subRoot->right);

    return (left && right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root) {
        return false;
    }

    // If this is the case
    if (root->val == subRoot->val) {
        // We start comparing the rest of the values in the subRoot against the values in the root
        bool subTreeInTree = compareSubtrees(root, subRoot);

        if (subTreeInTree) {
            return true;
        }
    }

    bool inLeft = isSubtree(root->left, subRoot);
    bool inRight = isSubtree(root->right, subRoot);

    return (inLeft || inRight);
}
// @leet end
