// @leet start
// My first idea was to create a massive array like this
// Node* table[MAX_VALUE * 2] = { NULL }; Where MAX_VALUE is 1000000000
// But that was kinda stupid

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10007

typedef struct entry {
    int val;
    struct entry* next;
} Entry;

typedef struct hashSet {
    Entry** entries;
} HashSet;

int hash(int val) {
    return abs(val) % TABLE_SIZE;
}

void insert(HashSet* set, int val) {
    int hashed = hash(val);
    Entry* current = set->entries[hashed];
    while (current) {
        if (current->val == val) {
            // Already exists so we skip it
            return;
        }
        current = current->next;
    }

    // Create a new entry that being separate chaining or just a new one
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->val = val;
    newEntry->next = set->entries[hashed];
    set->entries[hashed] = newEntry;
}

bool exists(HashSet* set, int val) {
    int hashed = hash(val);
    Entry* current = set->entries[hashed];
    while (current) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }

    return false;
}

HashSet* createHashSet() {
    // Create a new HashSet
    HashSet* set = (HashSet*)calloc(1, sizeof(HashSet));
    set->entries = (Entry**)calloc(TABLE_SIZE, sizeof(Entry*));

    return set;
}

void printSet(HashSet* set) {
    printf("Printing set...\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry* current = set->entries[i];
        while (current) {
            printf("{%d: %d},\n", i, current->val);
            current = current->next;
        }
    }
    printf("\n");

}

int longestConsecutive(int* nums, int numsSize) {
    // Create a new HashSet
    HashSet* set = createHashSet();

    // Append each value to the set
    for (int i = 0; i < numsSize; i++) {
        insert(set, nums[i]);
    }

    /*printSet(set);*/

    int longest = 0;
    int current = 0;

    for (int i = 0; i < numsSize; i++) {
        // Get the previous number for the current number
        bool previousExists = exists(set, nums[i] - 1);
        // If the previous number doesn't exist, this is the start of the sequence
        if (previousExists == false) {
            current = 1;
            // Check the next characters in the sequence
            // NOTE: I forgot the + 1 lol
            int next = nums[i] + 1;
            bool nextExists = exists(set, next);
            while (nextExists) {
                next += 1;
                current += 1;
                nextExists = exists(set, next);
            }

            // Update longest sequence
            longest = current > longest ? current : longest;
        }
    }

    return longest;
}
// @leet end
