// @leet start
int binarySearch(int* nums, int target, int left, int right) {
    if (left >= right) {
        return -1;
    }
    int middle = left + (right - left) / 2;

    if (nums[middle] == target) {
        return middle;
    }

    if (nums[middle] < target) {
        return binarySearch(nums, target, middle + 1, right);
    } else {
        return binarySearch(nums, target, left, middle - 1);
    }
}

int search(int* nums, int numsSize, int target) {
    return binarySearch(nums, target, 0, numsSize - 1);
}
// @leet end
