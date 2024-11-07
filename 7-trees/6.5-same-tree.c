// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // Do DFS and if it's not equal, return false
    // simple...
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    } else if (p->val != q->val){
        return false;
    }

    bool sameLeft = isSameTree(p->left, q->left);
    bool sameRight = isSameTree(p->right, q->right);

    if (sameLeft && sameRight) {
        return true;
    } else {
        return false;
    }
}
// @leet end
