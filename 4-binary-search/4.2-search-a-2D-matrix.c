// @leet start
#include <stdbool.h>

bool binarySearch(int** matrix, int nRows, int l, int r, int target) {
    if (l > r) {
        return false;
    }

    int middle = l + (r - l) / 2; // To avoid integer overflow

    int test = matrix[middle / nRows][middle % nRows];

    if (test > target) {
        // If we are to the right of the target, we have to move the right pointer left
        return binarySearch(matrix, nRows, l, middle - 1, target);

    } else if (test < target) {
        // Else if we are to the left of the target, we have to move the right pointer right
        return binarySearch(matrix, nRows, middle + 1, r, target);

    } else {
        // Else, we have found the value
        return true;
    }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    return binarySearch(matrix, *matrixColSize, 0, (matrixSize * *matrixColSize) - 1, target);
}
// @leet end
