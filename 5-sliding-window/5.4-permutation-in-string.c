// @leet start
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define HASHMAP_SIZE 26

int hash(char c) {
    return c - 'a';
}

void printHashMap(int* hashMap) {
    printf("HashMap: {\n");
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        char lowercase = 'a' + i;
        int count = hashMap[i];
        if (count != 0) {
            printf("    '%c': %d,\n", lowercase, count);
        }
    }
    printf("}\n");
}

bool isHashMapEmpty(int* hashMap) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        if (hashMap[i] != 0) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    // Initialize hashmaps
    int hashMap[HASHMAP_SIZE] = {0};

    for (int i = 0; i < strlen(s1); i++) {
        int hashedIndex = hash(s1[i]);
        hashMap[hashedIndex] += 1;
    }

    // Print hashmap
    /*printf("s1 ");*/
    /*printHashMap(hashMap);*/
    /*printf("\n");*/

    // Initialize left pointer
    int left = 0;
    int s2Length = strlen(s2);

    // Initialize right pointer and iterate through s2
    for (int right = 0; right < s2Length; right++) {
        int hashedIndex = hash(s2[right]);
        /*printf("Hashed index for %c: %d\n", s2[right], hash(s2[right]));*/

        // Reduce the count in the hashmap by 1
        hashMap[hashedIndex] -= 1;
        /*printHashMap(hashMap);*/

        // If the current count of the right pointer is less than 1
        while (hashMap[hashedIndex] <= -1) {
            // We increment the count and increment left
            hashMap[hash(s2[left])] += 1;
            left++;
        }

        if (isHashMapEmpty(hashMap)) {
            return true;
        }

    }

    return false;
}
// @leet end
