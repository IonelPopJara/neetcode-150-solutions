// @leet start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

// TODO: Do this one again in python

typedef struct HashMap {
    struct Node* original;
    struct Node* copy;
    struct HashMap* next;
} HashMap;

#define TABLE_SIZE 1000

int hash(struct Node* node) {
    return ((unsigned long)node) % TABLE_SIZE;
}

void insertHashMap(HashMap** table, struct Node* original, struct Node* copy) {
    int index = hash(original);
    HashMap* newEntry = (HashMap*)malloc(sizeof(HashMap));
    newEntry->original = original;
    newEntry->copy = copy;
    // Handle collisions
    newEntry->next = table[index];
    table[index] = newEntry;
}

struct Node* lookupHashMap(HashMap** table, struct Node* original) {
    int index = hash(original);
    HashMap* entry = table[index];
    while (entry) {
        if (entry->original == original) {
            return entry->copy;
        }
        entry = entry->next;
    }

    return NULL;
}

struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return NULL;
    }

    // Initialize the hastable
    HashMap* hashTable[TABLE_SIZE] = { NULL };

    struct Node* current = head;

    // First pass, copy each node and store it in the hashmap
    while (current) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = current->val;
        copy->next = NULL;
        copy->random = NULL;
        insertHashMap(hashTable, current, copy);
        current = current->next;
    }

    // Second pass, link the next and random pointers
    current = head;
    while (current) {
        struct Node* copy = lookupHashMap(hashTable, current);
        if (current->next) {
            copy->next = lookupHashMap(hashTable, current->next);
        }
        if (current->random) {
            copy->random = lookupHashMap(hashTable, current->random);
        }
        current = current->next;
    }

    // Return the head of the copied the list
    struct Node* copiedHead = lookupHashMap(hashTable, head);

    // Free the memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashMap* entry = hashTable[i];
        while (entry) {
            HashMap* tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }

    return copiedHead;
}
// @leet end
