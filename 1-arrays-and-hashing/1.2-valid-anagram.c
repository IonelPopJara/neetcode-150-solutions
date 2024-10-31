// @leet start
#include <stdbool.h>
#include <string.h>

#define HASH_SIZE 26

int hash(char c) {
    return c - 'a';
}

bool isAnagram(char* s, char* t) {
    int hashmap[HASH_SIZE] = { 0 };

    if (strlen(s) != strlen(t)) {
        return false;
    }

    char* c;

    // Iterate through the first string and update hashmap
    c = s;
    while (*c != '\0') {
        hashmap[hash(*c)] += 1;
        c++;
    }

    // Iterate through the second string and compare it
    c = t;
    while (*c != '\0') {
        int count = hashmap[hash(*c)];
        if (count == 0) {
            return false;
        }

        hashmap[hash(*c)] -= 1;
        c++;
    }

    return true;
}
// @leet end
