
// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10000
#define HASHMAP_SIZE (MAX_VALUE * 2)

#define TABLE_SIZE 10007

typedef struct node {
    int val;
    struct node* next;
} Node;

int hash(int val) {
    return val + MAX_VALUE;
}

// This is kinda stupid but it's a work around for not wanting to do a hashmap
int dehash(int val) {
    return val - MAX_VALUE;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    /*
     * Min and Max values for nums[i] => [-10000, 10000]
     * -10000 -map-> 0 | 0 -map-> 10000 | 10000 -map->20000
     */

    // Create a hashmap to map the numbers to their count
    // For example, for the input array [1, 1, 1, 2, 2, 3],
    // we get {MAX_VALUE + 1: 3, MAX_VALUE + 2: 2, MAX_VALUE + 3: 1}.
    int countMap[MAX_VALUE * 2] = { 0 }; // Array

    // Create an array to store the count of each number, where the index
    // of the array represent the count.
    // For example, for the countMap {MAX_VALUE + 1: 3, MAX_VALUE + 2: 2, MAX_VALUE + 3: 1},
    // we get [_, 3, 2, 1, _, _, _, _].
    // Where index 0 is not used since there is no element with count 0.
    int* countArray = (int*)malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++) {
        countArray[i] = -MAX_VALUE - 1;
    }

    // Iterate through the input array
    for (int i = 0; i < numsSize; i++) {
        // Update the count in countMap
        int hashed = hash(nums[i]);
        countMap[hashed] += 1;
    }

    // Iterate through the count map [0, 20000] where it maps to [-10000, 10000]
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        // Update the count array
        int count = countMap[i];
        if (count > 0) {
            countArray[count] = dehash(i);
        }
    }

    int* result = (int*)malloc(sizeof(int) * k);
    int resultCount = k;
    *returnSize = k;

    printf("\n");
    for (int i = numsSize; i > 0; i--) {
        printf("countArray[%d]: %d\n", i, countArray[i]);
    }
    printf("\n");

    // Iterate in revers order through the count array
    // Most frequent numbers will be last since they have higher indexes
    for (int i = numsSize; i > 0; i--) {
        printf("i: %d\n", i);
        if (resultCount == 0) {
            break;
        }
        // FIXME: Change this
        if (countArray[i] > -MAX_VALUE - 1) {
            printf("CountArray[%d]: %d\n", i, countArray[i]);
            result[resultCount - 1] = countArray[i];
            resultCount--;
        }
    }

    return result;
}
// @leet end
