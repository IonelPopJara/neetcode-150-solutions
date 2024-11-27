/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* root, long left, long right) {
    if (!root) {
        return true;
    }

    if (!(root->val < right && root->val > left)) {
        return false;
    }

    bool leftSideValid = helper(root->left, left, root->val);
    bool rightSideValid = helper(root->right, root->val, right);

    return leftSideValid && rightSideValid;
}

bool isValidBST(struct TreeNode* root) {

    bool left = helper(root->left, LONG_MIN, root->val);
    bool right = helper(root->right, root->val, LONG_MAX);

    return left && right;
}
