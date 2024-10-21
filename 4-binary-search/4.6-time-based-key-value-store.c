// @leet start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 5

unsigned int hash(char* key) {
    unsigned int hashedValue = 0;
    while (*key) {
        hashedValue += *key;
        key++;
    }
    return hashedValue % TABLE_SIZE;
}

typedef struct node {
    char* val;
    int timestamp;
} NODE;

typedef struct hashItem {
    char* key;
    int count;
    int arrSize;
    NODE** nodes; // A pointer to an array of nodes
    struct hashItem* next; // A pointer to another hashItem in case of collisions (separate chaining)
} HASHITEM;

typedef struct {
    HASHITEM* hashTable[TABLE_SIZE]; // A pointer to an array of hash items
} TimeMap;

TimeMap* timeMapCreate() {
    TimeMap* map = (TimeMap*)malloc(sizeof(TimeMap)); // Allocate memory for the map

    /*printf("Checking map creation...\n");*/
    for (int i = 0; i < TABLE_SIZE; i++) {
        // Separate the chaining is not working
        /*printf(" Setting hashTable[%d] to NULL\n", i);*/
        map->hashTable[i] = NULL;
    }
    /*printf("Map successfully created!\n\n");*/

    return map;
}

void printTimeMap(TimeMap* obj) {
    printf("Print TimeMap {\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        HASHITEM* item = obj->hashTable[i];
        printf("    Hash: %d\n", i);
        while(item != NULL) {
            printf("        Key: %s\n", item->key);
            for (int j = 0; j < item->count; j++) {
                if (item->nodes[j] != NULL) {
                    printf("            i: %d | Val: %s | TimeStamp: %d\n", j, item->nodes[j]->val, item->nodes[j]->timestamp);
                }
            }
            item = item->next;
        }
    }
    printf("}\n\n");
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    /*printf("Set (key: %s) with (value: %s) and (timestampt: %d)\n", key, value, timestamp);*/

    // Get the hashed value of the key
    unsigned int hashed = hash(key); 
    /*printf("    hashed key: %d\n", hashed);*/

    // Get the current item at the specified index (hashed)
    HASHITEM* previous = NULL;
    HASHITEM* current = obj->hashTable[hashed];

    // Check if for collisions (two hashed values are the same)
    while (current != NULL) {
        /*printf("        hashTable[%d] -> %s\n", hashed, current->key);*/
        // If the hashed values and the keys are the same, we will append another timestamp
        if (strcmp(current->key, key) == 0) {
            break;
        }

        // If we have different keys, we will handle collisions
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // If current is NULL, we create a new key
        // Allocate memory and assign the key to the hashitem
        current = (HASHITEM*)malloc(sizeof(HASHITEM));
        current->key = strdup(key);
        // Make an array size of 1 for dynamic arrays
        current->arrSize = 1;
        current->nodes = (NODE**)malloc(sizeof(NODE*) * current->arrSize);
        // Add the node to the array of timestamps
        current->count = 0;
        current->nodes[current->count] = (NODE*)malloc(sizeof(NODE));
        current->nodes[current->count]->val = strdup(value);
        current->nodes[current->count]->timestamp = timestamp;
        // Update the node count
        current->count = 1;
        // Update the next pointer
        current->next = NULL;

        if (previous == NULL) {
            // If previous is NULL, we insert an item for the first time
            /*printf("        create a new key for hashTable[%d] -> NULL\n", hashed);*/
            obj->hashTable[hashed] = current;
        } else {
            // Otherwise, we append to an existing item
            /*printf("        chain a new key for hashTable[%d] -> NULL\n", hashed);*/
            previous->next = current;
        }
    } else {
        // Otherwise, we append the timestamp to an existing key
        /*printf("        append timestampt to key hashTable[%d] -> %s\n", hashed, current->key);*/
        // Account for resizing if needed
        /*printf("            current->count = %d\n", current->count);*/
        if (current->count >= current->arrSize) {
            /*printf("                resize nodes because count(%d) >= size(%d)\n", current->count, current->arrSize);*/
            current->arrSize *= 2;
            /*printf("                new current->arrSize = %d | current->count = %d\n", current->arrSize, current->count);*/
            current->nodes = (NODE**)realloc(current->nodes, sizeof(NODE*) * current->arrSize);
        }

        // Add the new timestamp pair
        current->nodes[current->count] = (NODE*)malloc(sizeof(NODE));
        current->nodes[current->count]->val = strdup(value);
        current->nodes[current->count]->timestamp = timestamp;
        current->count++;
    }

    /*printf("Added item (%s, %s) at index %d with timestamp %d...\n\n", key, value, hashed, timestamp);*/

    /*printTimeMap(obj);*/
}

int binarySearch(NODE** nodes, int l, int r, int target, int previous) {
    /*printf("        l: %d | r: %d\n", l, r);*/
    if (l > r) {
        /*printf("        finish binary search\n");*/
        /*printf("            nodes[previous]->timestamp = %d\n", nodes[previous]->timestamp);*/
        if (nodes[previous]->timestamp < target) {
            return previous;
        } else {
            return -1;
        }
    }

    int middle = l + (r - l) / 2;
    /*printf("        binary search nodes[middle]->timestamp: %d | target: %d\n", nodes[middle]->timestamp, target);*/

    if (nodes[middle]->timestamp == target) {
        /*printf("        finish binary search\n");*/
        /*printf("            timestamp found\n");*/
        return middle;
    } else if (nodes[middle]->timestamp > target) {
        /*printf("        move middle down\n");*/
        return binarySearch(nodes, l, middle - 1, target, previous);
    } else {
        /*printf("        move middle up\n");*/
        return binarySearch(nodes, middle + 1, r, target, middle);
    }
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    /*printTimeMap(obj);*/
    /*printf("Get timestamp %d for key %s\n", timestamp, key);*/

    // Get the hashed value
    unsigned int hashed = hash(key);
    HASHITEM* current = obj->hashTable[hashed];

    // Check for collisions
    while (current != NULL) {
        // If we find the hashItem with the correct key, we use that one
        if (strcmp(current->key, key) == 0) {
            int maxIndex = current->count - 1;
            // TODO: Implement binary search here
            int res = binarySearch(current->nodes, 0, maxIndex, timestamp, 0);
            /*printf("    Binary Search Result: %d\n", res);*/

            if (res > -1) {
                return current->nodes[res]->val;
            }
            else {
                return "";
            }

        }
        current = current->next;
    }

    // Key not found
    return "";
}

void timeMapFree(TimeMap* obj) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HASHITEM* current = obj->hashTable[i];
        while (current != NULL) {
            HASHITEM* temp = current;
            current = current->next;
            for (int j = 0; j < temp->count; j++) {
                free(temp->nodes[j]->val);
                free(temp->nodes[j]);
            }
            free(temp->nodes);
            free(temp->key);
            free(temp);
        }
    }
    free(obj);
}

/**
 * Your TimeMap struct will be instantiated and called as such:
 * TimeMap* obj = timeMapCreate();
 * timeMapSet(obj, key, value, timestamp);

 * char* param_2 = timeMapGet(obj, key, timestamp);

 * timeMapFree(obj);
*/
// @leet end
