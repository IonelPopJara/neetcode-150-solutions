/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define QUEUE_SIZE 2000

struct TreeNode* queue[QUEUE_SIZE] = { NULL };
int head = 0;
int tail = 0;

void enqueue(struct TreeNode** queue, struct TreeNode* node) {
    queue[tail] = node;
    tail++;
    tail = tail % QUEUE_SIZE;
}

struct TreeNode* dequeue(struct TreeNode** queue) {
    if (head == tail) {
        return NULL;
    }

    struct TreeNode* currentNode = queue[head];
    head++;
    head = head % QUEUE_SIZE;

    return currentNode;
}

int isEmpty(struct TreeNode** queue) {
    return head == tail ? 1 : 0;

}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Allocate space for results
    int** result = (int**)malloc(QUEUE_SIZE * sizeof(int*));
    *returnColumnSizes = (int*)malloc(QUEUE_SIZE * sizeof(int));
    *returnSize = 0;

    enqueue(queue, root);

    while (isEmpty(queue) == 0) {
        int levelSize = tail - head;
        if (levelSize < 0) levelSize += QUEUE_SIZE;

        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = dequeue(queue);
            result[*returnSize][i] = current->val;

            if (current->left) {
                enqueue(queue, current->left);
            }

            if (current->right) {
                enqueue(queue, current->right);
            }

        }
        (*returnSize)++;
    }

    return result;
}
