// @leet start
#include <stdio.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    // Get the length of the input string
    int length = strlen(s);
    int maxLength = 1;

    // Initialize hashmap...
    int hashMap[10000];
    printf("Initialize hashmap...\n");
    for (int i = 0; i < 10000; i++) {
        hashMap[i] = 0;
    }

    // If the length of the string is 1, we return 1
    if (length <= 1) {
        return length;
    }

    // Initialize left and right pointers and add the left character to our hashmap
    int left = 0;
    int right = 1;
    hashMap[s[left]] = 1;

    while (right < length) {
        printf("Checking for [%d | (L: %c)] and [%d | (R: %c)]\n", left, s[left], right, s[right]);
        // If the right character not in the hashmap
        if (hashMap[s[right]] == 0) {
            printf("    (R: %c) is not in the hashmap\n", s[right]);
            hashMap[s[right]] = 1;
        // Otherwise, if the right character is already in the hashmap
        } else {
            printf("    (R: %c) is already in the hashmap\n", s[right]);
            // Calculate max length
            maxLength = MAX(right - left, maxLength);
            printf("        Substring length: %d\n", right - left);

            // Move the left pointer until the left pointer and right pointer are not the same characters
            printf("        incrementing left pointer...\n");
            hashMap[s[right]] += 1;
            printf("        hashMap[s[right]] = %d\n", hashMap[s[right]]);
            while (left < right && hashMap[s[right]] > 1) {
                hashMap[s[left]] -= 1;
                left++;
            }

        }

        right++;
    }

    return MAX(right-left,maxLength);
}
// @leet end
