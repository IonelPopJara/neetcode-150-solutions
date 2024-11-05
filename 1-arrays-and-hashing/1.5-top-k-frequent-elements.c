// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 17

typedef struct entry {
    int key;
    int val;
    struct entry* next;
} Entry;

typedef struct hashTable {
    Entry** entries;
} HashTable;

HashTable* initHashTable() {
    HashTable* table = (HashTable*)calloc(1, sizeof(HashTable));

    table->entries = (Entry**)calloc(TABLE_SIZE, sizeof(Entry*));

    return table;
}

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(HashTable* table, int key, int val) {
    int hashed = hash(key);
    Entry* current = table->entries[hashed];
    while (current) {
        if (current->key == key) {
            break;
        }
        current = current->next;
    }

    if (current) {
        // If we found an already existing key, we update it
        current->val = val;
    } else {
        // Otherwise, we insert a new node (separate chaining)
        Entry* newEntry = (Entry*)calloc(1, sizeof(Entry));
        newEntry->key = key;
        newEntry->val = val;
        newEntry->next = table->entries[hashed];
        table->entries[hashed] = newEntry;
    }
}

Entry* get(HashTable* table, int key) {
    int hashed = hash(key);
    Entry* current = table->entries[hashed];
    while (current) {
        if (current->key == key) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void printHashTable(HashTable* table) {
    printf("Printing hash table...\n");
    printf("{");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry* current = table->entries[i];
        while (current) {
            printf("%d: %d, ", current->key, current->val);
            current = current->next;

        }
    }
    printf("}\n");
}


int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    // Input Array: [min, max] | [-10000, 10000]
    //  [1, 1, 2, 3, 3]
    //  map to -> {1: 2, 2: 1, 3: 2} (dictionary)
    HashTable* countTable = initHashTable();
    for (int i = 0; i < numsSize; i++) {
        Entry* current = get(countTable, nums[i]);

        if (current) {
            // If it already exists, increment the value (count)
            insert(countTable, nums[i], current->val + 1);
        } else {
            // Otherwise create a new entry
            insert(countTable, nums[i], 1);
        }
    }

    /*printHashTable(countTable);*/

    // Map {1: 2, 2: 1, 3: 2} to
    // [X, 2, [1, 3], _, _, _] (1-index list of numsSize + 1. Index 0 is useless)
    int** freqGroup = (int**)calloc(numsSize + 1, sizeof(int*));
    int* freqGroupSizes = (int*)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry* current = countTable->entries[i];
        // NOTE: For some reason this while was an if and it took me 5 minutes to realize
        while (current) {
            int freq = current->val;
            freqGroupSizes[freq]++; // If I have two elements with the same freq, [1, 2] -> freq = 1, update freqGroupSizes[1]
            freqGroup[freq] = (int*)realloc(freqGroup[freq], freqGroupSizes[freq] * sizeof(int));
            // Add it to the list of lists
            freqGroup[freq][freqGroupSizes[freq] - 1] = current->key;
            current = current->next;
        }
    }

    // Print list of lists
    /*printf("\nPrinting frequency list...\n");*/
    /*for (int i = 0; i < numsSize; i++) {*/
    /*    printf("    freqGroup[%d]:\n", i);*/
    /*    for (int j = 0; j < freqGroupSizes[i]; j++) {*/
    /*        printf("        [%d]: %d\n", j, freqGroup[i][j]);*/
    /*    }*/
    /*}*/
    /*printf("\n");*/

    *returnSize = k;

    int* result = (int*)calloc(k, sizeof(int));
    int resultIndex = 0;

    for (int i = numsSize; i > 0 && resultIndex < k; i--) {
        // We have a frequency
        if (freqGroupSizes[i] > 0) {
            for (int j = 0; j < freqGroupSizes[i] && resultIndex < k; j++) {
                result[resultIndex] = freqGroup[i][j];
                resultIndex++;
            }
        }
    }

    return result;
}
// @leet end
