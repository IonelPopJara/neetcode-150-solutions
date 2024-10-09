// @leet start
int binarySearchMod(int* nums, int l, int r, int previousMin) {
    // If the array is sorted
    if (nums[l] <= nums[r]) {
        // Return the minimum between the previous minimum and the currentn minimum
        return previousMin < nums[l] ? previousMin : nums[l];
    }

    // Perform the custom binary search for a rotated array
    int middle = l + (r - l) / 2; // To avoid integer overflow
    previousMin = nums[middle]; // Update previousMin

    // If the current element is bigger than the leftmost element in the subarray
    // For example: [3, 4, 5, 1, 2]
    //              [l, _, m, _, r]
    if (nums[middle] >= nums[l]) {
        // Search the right part of the subarray
        return binarySearchMod(nums, middle + 1, r, previousMin);
    } else {
        // Otherwise, search the left part of the subarray
        // For example: [4, 5, 1, 2, 3] -- in this case, we also updated previous min to consider it for our next call
        //              [l, _, m, _, r]
        return binarySearchMod(nums, l, middle - 1, previousMin);
    }
}

int findMin(int* nums, int numsSize) {
    return binarySearchMod(nums, 0, numsSize -1, nums[0]);
}
// @leet end
