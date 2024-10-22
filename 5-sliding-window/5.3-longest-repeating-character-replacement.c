// @leet start
#include <string.h>

#define HASHMAP_SIZE 26

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int hash(char s) {
    return s - 'A';
}

/**
 * This is slightly optimized version that does not require to use
 * the O(26) function `findMaxFreq`.
 *
 * While more efficient it is less intuitive and that makes it sort
 * of pointless in my opinion.
 */
int characterReplacementFaster(char* s, int k) {
    // Initialize hashmap to store uppercase letters
    int hashMap[HASHMAP_SIZE] = {0};

    // Initialize maxLength
    int maxLength = 0;

    // Get the length of the string
    int length = strlen(s);

    // Initialize left pointer
    int left = 0;

    // Initialize maxFreq because of silly optimization
    // I didn't come up with this and I actually think it's kinda pointless but sure
    int maxFreq = 0;

    // Initialize right pointer and iterate
    for (int right = 0; right < length; right++) {
        // Add the right pointer to the hash map
        int hashIndex = hash(s[right]);
        hashMap[hashIndex] += 1;

        // Update maxFreq
        maxFreq = MAX(hashMap[hashIndex], maxFreq);

        // Shrink the window until the we can make replacements
        // length = right - left + 1
        // => length - maxFreq > k
        while (right - left + 1 - maxFreq > k) {
            // Remove the left character from the hashmap
            int hashIndex = hash(s[left]);
            hashMap[hashIndex] -= 1;

            // Increment the left pointer
            left++;
        }

        // Update max length
        maxLength = MAX(right - left + 1, maxLength);
    }

    return maxLength;
}

int findMaxFreq(int* hashMap) {
    int max = 0;
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        max = MAX(hashMap[i], max);
    }

    return max;
}

int characterReplacement(char* s, int k) {
    // Initialize hashmap to store uppercase letters
    int hashMap[HASHMAP_SIZE] = {0};

    // Initialize maxLength
    int maxLength = 0;

    // Get the length of the string
    int length = strlen(s);

    // Initialize left pointer
    int left = 0;

    // Initialize right pointer and iterate
    for (int right = 0; right < length; right++) {
        // Add the right pointer to the hash map
        int hashIndex = hash(s[right]);
        hashMap[hashIndex] += 1;

        // Shrink the window until the we can make replacements
        // length = right - left + 1
        // => length - maxFreq > k
        while (right - left + 1 - findMaxFreq(hashMap) > k) {
            // Remove the left character from the hashmap
            int hashIndex = hash(s[left]);
            hashMap[hashIndex] -= 1;

            // Increment the left pointer
            left++;
        }

        // Update max length
        maxLength = MAX(right - left + 1, maxLength);
    }

    return maxLength;
}
// @leet end
