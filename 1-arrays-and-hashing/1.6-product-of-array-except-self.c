// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size - 1]);
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* result = (int*)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    // Generate prefixProduct

    int cum = 1; // short for cum-mulative
    result[0] = cum;
    for (int i = 0; i < numsSize - 1; i++) {
        cum *= nums[i];
        result[1 + i] = cum;
    }

    // Generate suffixProduct
    cum = 1; // reset cum-mulative
    for (int i = numsSize - 1; i >= 1; i--) {
        cum *= nums[i];
        result[i - 1] *= cum;
    }

    return result;

    /*printf("Prefix product: ");*/
    /*printArray(prefixProduct, numsSize);*/
    /*printf("Suffix product: ");*/
    /*printArray(suffixProduct, numsSize);*/

    // Index:           [0 , 1 , 2 , 3 ]
    // Input array:     [1 , 2 , 3 , 4 ]
    // Prefix product:  [1 , 2 , 6 , 24]
    // Suffix product:  [24, 24, 12, 4 ]
    // Result:          [24, 12, 8 , 6 ]
    // for an index i, result = preffix[i - 1] * suffix[i + 1]
    // for i = 2, result = preffix[1] * suffix[3] = 2 * 4 = 8

    /*for (int i = 0; i < numsSize; i++) {*/
    /*    int prefix = 1;*/
    /*    int suffix = 1;*/
    /*    if (i - 1 >= 0) {*/
    /*        prefix = prefixProduct[i - 1];*/
    /*    }*/
    /**/
    /*    if (i + 1 < numsSize) {*/
    /*        suffix = suffixProduct[i + 1];*/
    /*    }*/
    /**/
    /*    result[i] = prefix * suffix;*/
    /*}*/
}
// @leet end
