#include <stdlib.h>

// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* indexes = (int*)malloc(2 * sizeof(int));

    int i = 0;
    int j = numbersSize - 1;
    while (i < j) {
        // Calculate the sum
        int sum = numbers[i] + numbers[j];

        // If the sum is too big
        if (sum > target) {
            // Move the right pointer backward
            j--;
        }
        else if (sum < target) {
            // Otherwise, move the left pointer forward
            i++;
        }
        else {
            indexes[0] = i + 1;
            indexes[1] = j + 1;
            break;
        }
    }

    return indexes;
}
// @leet end
