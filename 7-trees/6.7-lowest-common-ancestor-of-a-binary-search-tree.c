// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) {
        return NULL;
    }

    // printf("Root->val: %d | p: %d | q: %d\n", root->val, p->val, q->val);
    if (p->val > root->val && q->val > root->val) {
        // printf("Search right subtree\n");
        return lowestCommonAncestor(root->right, p, q);
    } else if (p->val < root->val && q->val < root->val) {
        // printf("Search left subtree\n");
        return lowestCommonAncestor(root->left, p, q);
    } else {
        // printf("LCA Found\n");
        return root;
    }
}
// @leet end
