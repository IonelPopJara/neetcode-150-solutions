// @leet start
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASHMAP_SIZE 10007 // Prime number for better hashing, I think

// Define a hashmap node
typedef struct node {
    int val;
    struct node* next; // next is used for separate chaining
} Node;

int hash(int val) {
    int hashed = val & HASHMAP_SIZE;
    /*printf("Hashed %d: %d\n", val, hashed);*/
    if (hashed >= HASHMAP_SIZE) {
        printf("Value: %d | %d\n", val, hashed);
        hashed = 0;
    }

    return hashed;
}

void insert(Node* hashmap[], int val) {
    int hashed = hash(val);

    // If there is no other element with the same hash value
    if (hashmap[hashed] == NULL) {
        /*printf("    hash empty\n");*/

        hashmap[hashed] = (Node*)malloc(sizeof(Node));
        hashmap[hashed]->val = val;
        hashmap[hashed]->next = NULL;
    } else {
        // If there is already another element with the same hash value
        Node* current = hashmap[hashed];
        // If the current node is null or the current node's value is the one we want to insert, we break the loop
        while (current && current->val != val){
            current = current->next;
        }

        if (current == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = val;
            // Update the head of the list
            newNode->next = hashmap[hashed];
            hashmap[hashed] = newNode;
        }
    }
}

bool exists(Node* hashmap[], int val) {
    int hashed = hash(val);

    Node* current = hashmap[hashed];
    while (current) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    // Create hashmap
    Node* hashmap[HASHMAP_SIZE] = { NULL };

    for (int i = 0; i < numsSize; i++) {
        // If we find a duplicate, return true
        if (exists(hashmap, nums[i])) {
            return true;
        }

        // Otherwise, add the element to the hashmap
        insert(hashmap, nums[i]);
    }

    return false;
}
// @leet end
