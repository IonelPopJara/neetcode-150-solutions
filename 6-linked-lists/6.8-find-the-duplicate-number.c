// @leet start
int findDuplicate(int* nums, int numsSize) {
    // Use that silly tortoise and hare algorithm
    int slow = 0;
    int fast = 0;

    // Find the interesection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow != fast);

    // Find the start of the cycle
    int secondSlow = 0;
    while (slow != secondSlow) {
        slow = nums[slow];
        secondSlow = nums[secondSlow];
    }

    return slow;
}
// @leet end
