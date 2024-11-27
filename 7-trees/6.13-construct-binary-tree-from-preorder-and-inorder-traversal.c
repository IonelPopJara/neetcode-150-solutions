/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    // Find the midIndex
    int midIndex = 0;
    while (inorder[midIndex] != preorder[0]) {
        midIndex++;
    }

    root->left = buildTree(preorder + 1, midIndex, inorder, midIndex);
    root->right = buildTree(preorder + 1 + midIndex, preorderSize - 1 - midIndex, inorder + 1 + midIndex, inorderSize - midIndex - 1);

    return root;
}
