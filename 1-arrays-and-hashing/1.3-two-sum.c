// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007 // Prime number for better collisions

typedef struct node {
    int key;
    int val;
    struct node* next;
} Node;

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(Node* hashMap[], int key, int value) {
    int hashed = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    newNode->next = hashMap[hashed];
    hashMap[hashed] = newNode;
}

int get(Node* hashMap[], int key) {
    int index = -1;

    int hashed = hash(key);
    Node* current = hashMap[hashed];

    while (current && current->key != key) {
        current = current->next;
    }

    if (current) {
        return current->val;
    }

    return index;
}

void printHashMap(Node* hashMap[]) {
    printf("Printing HashMap (num, idx)...\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashMap[i]) {
            Node* current = hashMap[i];
            printf("    %d: %d\n", current->key, current->val);
            current = current->next;
            while (current) {
                printf("    ~%d: %d\n", current->key, current->val);
                current = current->next;
            }
        }
    }
}

void freeHashMap(Node* hashMap[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashMap[i];
        while (current) {
            Node* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    Node* hashMap[TABLE_SIZE] = { NULL }; // Initialize a hashmap

    for (int i = 0; i < numsSize; i++) {
        int comp = target - nums[i];
        int compIdx = get(hashMap, comp);
        if (compIdx != -1) {
            result[0] = compIdx;
            result[1] = i;

            freeHashMap(hashMap);
            return result;
        }

        insert(hashMap, nums[i], i);
    }
    return result;
}
// @leet end
