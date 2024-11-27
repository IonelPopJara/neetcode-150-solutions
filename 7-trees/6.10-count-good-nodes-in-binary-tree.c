/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int max, int count) {
    if (!root) {
        return 0;
    }

    max = root->val >= max ? root->val : max;

    int nNodesLeft = dfs(root->left, max, count); // 1
    int nNodesRight = dfs(root->right, max, count);
    
    if (root->val >= max) {
        // printf("%d is a good node\n", root->val);
        count += 1;
    }

    return nNodesLeft + nNodesRight + count;
}

int goodNodes(struct TreeNode* root) {

    return dfs(root, root->val, 0);
}
