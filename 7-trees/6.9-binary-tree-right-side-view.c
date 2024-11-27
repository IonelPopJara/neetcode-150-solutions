/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define QUEUE_SIZE 2000

typedef struct TreeNode* Queue;

Queue queue[QUEUE_SIZE] = { NULL };
int head = 0;
int tail = 0;

int isEmpty(Queue* queue) {
    return head == tail ? 1 : 0;
}

void enqueue(Queue* queue, struct TreeNode* node) {
    queue[tail] = node;
    tail++;
}

struct TreeNode* dequeue(Queue* queue) {
    if (isEmpty(queue) == 1) {
        return NULL;
    }

    struct TreeNode* result = queue[head];
    head++;
    return result;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *result = calloc(100, sizeof(int));
    int count = 0;

    enqueue(queue, root);

    while (isEmpty(queue) == 0) {
        int levelSize = tail - head;

        // printf("Level Size: %d\n", levelSize);

        int rightSide = -101;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = dequeue(queue);
            rightSide = current->val;
            // printf("\tcurrent->: %d\n", current->val);

            if (current->left) {
                enqueue(queue, current->left);
            }

            if (current->right) {
                enqueue(queue, current->right);
            }
        }

        result[count++] = rightSide;
        printf("Right side: %d | Count: %d\n", rightSide, count);

    }

    *returnSize = count;
    return result;
}
