// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// TODO: Do this in Python

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_SIZE 10007

typedef struct node {
    char* str;
    struct node* next;
} Node;

typedef struct hashMapEntry {
    char* key;
    Node* values;
    int count;
    struct hashMapEntry* next;
} HashMapEntry;

char* createKey(int* count) {
    char buffer[10];
    char* key = (char*)malloc(sizeof(char) * 100);
    key[0] = '\0';

    for (int i = 0; i < 26; i++) {
        sprintf(buffer, "%d_", count[i]);
        strcat(key, buffer);
    }

    return key;
}

int hash(char* key) {
    int h = 0;
    while (*key) {
        h = (h * 31 + *key) % HASHMAP_SIZE;
        key++;
    }

    return h;
}

void insert(HashMapEntry* hashMap[], int* count, char* string) {
    // Generate hash key
    char* key = createKey(count);
    int hashed = hash(key);
    HashMapEntry* current = hashMap[hashed];

    while (current && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    // If current is NULL, we create a new entry (separate chaining)
    if (current == NULL) {
        HashMapEntry* newEntry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
        newEntry->key = strdup(key);
        newEntry->count = 1;
        newEntry->next = hashMap[hashed];
        hashMap[hashed] = newEntry;
        newEntry->values = (Node*)malloc(sizeof(Node));
        newEntry->values->str = strdup(string);
        newEntry->values->next = NULL;
    } else {
        // If current is not null, we append a string to an already existing entry
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->str = strdup(string);
        newNode->next = current->values;
        Node* currentString = hashMap[hashed]->values;
        current->values = newNode;
        current->count += 1;
    }

    free(key);
}

void printHashMap(HashMapEntry* hashMap[]) {
    printf("Printing hashmap...\n");
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        if (hashMap[i]) {
            HashMapEntry* current = hashMap[i];
            printf("hashMap[%d]\n", i);
            while (current) {
                printf("    key: %s\n", current->key);
                printf("        strings:");
                Node* currentString = current->values;
                while (currentString) {
                    printf(" %s |", currentString->str);
                    currentString = currentString->next;
                }
                printf("\n");
                current = current->next;
            }
        }
    }
}

int getHashMapSize(HashMapEntry* hashMap[]) {
    int size = 0;
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        HashMapEntry* current = hashMap[i];
        while (current) {
            size ++;
            current = current->next;
        }
    }

    return size;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    HashMapEntry* hashMap[HASHMAP_SIZE] = { NULL };

    for (int i = 0; i < strsSize; i++) {
        // Create count array
        int count[26] = { 0 };
        char* c = strs[i];
        while (*c) {
            count[*c - 'a'] += 1;
            c++;
        }

        insert(hashMap, count, strs[i]);
    }

    /*printHashMap(hashMap);*/
    *returnSize = getHashMapSize(hashMap);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    char*** result = (char***)malloc(sizeof(char**) * (*returnSize));

    int row = 0;
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        HashMapEntry* current = hashMap[i];
        while (current) {
            (*returnColumnSizes)[row] = current->count;
            result[row] = (char**)malloc(sizeof(char*) * current->count);

            Node* currentNode = current->values;
            for (int col = 0; col < current->count; col++) {
                result[row][col] = strdup(currentNode->str);
                currentNode = currentNode->next;
            }
            row ++;
            current = current->next;
        }
    }

    return result;
}
// @leet end
