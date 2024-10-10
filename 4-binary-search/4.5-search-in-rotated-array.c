// @leet start
// NOTE: I did not fully understand this problem
int binarySearchCustom(int* input, int l, int r, int target) {
    // 1 <= 1 < 4
    // [1, 2, 3, 0] k = 1
    // [2, 3, 0, 1] k = 2
    // [3, 0, 1, 2] k = 3
    if (l > r) {
        return -1;
    }
    // [4,5,6,7,0,1,2]
    // middle = 3;
    int middle = l + (r - l) / 2;
    if (input[middle] == target) {
        return middle; // Index found
    }

    // [4,5,6,7,0,1,2]
    // [l,_,_,m,_,_,r]
    // target = 0
    // Check for the left sorted portion
    if (input[l] <= input[middle]) {
        if (target > input[middle] || target < input[l]) {
            // Search the right subarray
            return binarySearchCustom(input, middle + 1, r, target);
        } else {
            // Search the left subarray
            return binarySearchCustom(input, l, middle - 1, target);
        }
    }
    // [6,0,1,2,3,4,5]
    // [l,_,_,m,_,_,r]
    // target = 0
    // Else, check the right sorted portion
    else {
        if (target < input[middle] || target > input[r]) {
            return binarySearchCustom(input, l, middle - 1, target);
        } else {
            return binarySearchCustom(input, middle + 1, r, target);
        }
    }
}
int search(int* nums, int numsSize, int target) {
    return binarySearchCustom(nums, 0, numsSize - 1, target);
}
// @leet end
