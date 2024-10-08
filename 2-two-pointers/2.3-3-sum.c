// @leet start
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void merge(int* input, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Copy the contents of the original array to temporary ones
    int leftArr[n1];
    for (int i = 0; i < n1; i++) {
        leftArr[i] = input[left + i];
    }

    int rightArr[n2];
    for (int j = 0; j < n2; j++) {
        rightArr[j] = input[middle + 1 + j];
    }

    // Iterate through the arrays and put the results in order
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] < rightArr[j]) {
            input[k] = leftArr[i];
            i++;
        } else {
            input[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Add the remaining elements
    while (i < n1) {
        input[k++] = leftArr[i++];
    }

    while (j < n2) {
        input[k++] = rightArr[j++];
    }

}

void mergesort(int* input, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2; // This method avoids integer overflow
    mergesort(input, left, middle);
    mergesort(input, middle + 1, right);
    merge(input, left, middle, right);

    return;
}

void printArray(const char* str, int* input, int startIndex, int endIndex, const char* end) {
    printf("%s[", str);
    for (int i = startIndex; i < endIndex; i++) {
        printf("%d, ", input[i]);
    }
    printf("%d]%s", input[endIndex], end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    /*printArray("Array: ", nums, 0, numsSize - 1, "\n");*/
    mergesort(nums, 0, numsSize - 1);
    /*printArray("Sorted Array: ", nums, 0, numsSize - 1, "\n");*/

    int** result = (int**)malloc(7 * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(7 * numsSize * sizeof(int));

    int y = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        /*printf("Checking for %d...\n", nums[i]);*/
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                /*printf("Solution: [%d, %d, %d]\n", nums[i], nums[l], nums[r]);*/
                result[y] = (int*)malloc(3 * sizeof(int));
                result[y][0] = nums[i];
                result[y][1] = nums[l];
                result[y][2] = nums[r];
                (*returnColumnSizes)[y] = 3;
                y++;
                l++;
                while (nums[l] == nums[l - 1] && l < r) {
                    l++;
                }
            }
        }
    }

    *returnSize = y;
    return result;
}
// @leet end
