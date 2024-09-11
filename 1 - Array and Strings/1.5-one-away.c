#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Problem description:
 * 
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 * 
 * My idea: (Didn't work)
 * 
 * I can use a counter for the characters in str1. Then, I can iterate
 * through str2 and update the first counter accordingly. If the character
 * in str2 exists in the counter, I can subtract 1, if it's not in the counter,
 * or the counter is already 0, I can count that as 1 edit. Since I can only
 * perform 1 edit, after finding another one of those cases, the program
 * will exit.
 * 
 * For example:
 * 
 * 1. Insert a character
 * 
 * str1 = "pale";
 * str2 = "pales";
 * 
 * str1->count->[p:1, a:1, l:1, e:1]
 * str2->iterate->
 *      p -> exists in count -> [p:0, a:1, l:1, e:1]
 *      a -> exists in count -> [p:0, a:0, l:1, e:1]
 *      l -> exists in count -> [p:0, a:0, l:0, e:1]
 *      e -> exists in count -> [p:0, a:0, l:0, e:0]
 *      s -> does not exist in count -> +1 edit -> newCharacters = 1
 * 
 * Since the sum of counters is 0 and newCharacters = 1, return true (it is one away)
 * 
 * 2. Remove a character
 * 
 * str1 = "pale";
 * str2 = "ple";
 * 
 * str1->count->[p:1, a:1, l:1, e:1]
 * str2->iterate->
 *      p -> exists in count -> [p:0, a:1, l:1, e:1]
 *      l -> exists in count -> [p:0, a:1, l:0, e:1]
 *      e -> exists in count -> [p:0, a:1, l:1, e:0]
 * 
 * Since the sum of counters is 1, and there are 0 new characters, return true (it is one away).
 * 
 * 3. Replace a character
 * 
 * str1 = "pale";
 * str2 = "bale";
 * 
 * str1->count->[p:1, a:1, l:1, e:1]
 * str2->iterate->
 *      b -> does not exist in count -> +1 edit -> newCharacters = 1
 *      a -> exists in count -> [p:1, a:0, l:1, e:1]
 *      l -> exists in count -> [p:1, a:0, l:0, e:1]
 *      e -> exists in count -> [p:1, a:0, l:0, e:0]
 * 
 * Since the sum of counters is 1, and newCharacter = 1, return true (it is one away).
 * 
 * 4. Not one away
 * 
 * str1 = "pale";
 * str1 = "bake";
 * str1->count->[p:1, a:1, l:1, e:1]
 * str2->iterate->
 *      b -> does not exist in count -> +1 edit -> newCharacters = 1
 *      a -> exists in count -> [p:1, a:0, l:1, e:1]
 *      b -> does not exist in count -> +1 edit -> newCharacters = 2, here we could just exit
 *      e -> exists in count -> [p:1, a:0, l:1, e:0]
 * 
 * Since the sum of counters is 2, and newCharacter = 2, return false (it is not one away)
 * 
 * Note:
 * 
 * My first solution did not account for the fact that the letters could swap order,
 * as I was only taking into consideration their existence in the array. Therefore,
 * I had to look up a solution and it looks a bit more organized.
 * Basically there are 3 cases: difference in length greater than 1, 1 difference in length,
 * and equal length.
 * 
 * 1. If the lengths have a difference of more than 1, we just return false.
 * 2. If the lengths are equal, we compare each character. If a character don't match we count that
 * as one edit. If there are more than 1 edits, we return false.
 * 3. If the lengths have a difference of 1, we compare each character. When a character does not match,
 * we count that as one edit, and we compare the next character in the longest array without moving from
 * the shortest array (2 pointers). If there are more than 1 edits, we return false.
*/

#define true 1
#define false 0

int isOneAway(char* str1, char* str2);

int main()
{
    assert(isOneAway("aaa", "aaa") == true);
    printf("Test 0 passed :)\n");

    assert(isOneAway("pale", "pales") == true);
    printf("Test 1 passed :)\n");

    assert(isOneAway("pale", "ple") == true);
    printf("Test 2 passed :)\n");

    assert(isOneAway("pale", "bale") == true);
    printf("Test 3 passed :)\n");

    assert(isOneAway("pale", "bake") == false);
    printf("Test 4 passed :)\n");

    assert(isOneAway("pales", "ple") == false);
    printf("Test 5 passed :)\n");

    assert(isOneAway("abc", "bca") == false);
    printf("Test 6 passed :)\n");

    printf("All tests passed!");

    return 0;
}

int isOneAway(char* str1, char* str2)
{
    int lengthDifference = abs(strlen(str1) - strlen(str2));

    int edits = 0;
    if (lengthDifference > 1)
    {
        return false;
    }
    else if (lengthDifference == 0)
    {
        for (int i = 0; i < strlen(str2); i++)
        {
            if (str1[i] != str2[i])
            {
                edits += 1;
                if (edits > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else 
    {
        int i = 0;
        char *shortest, *longest;
        if (strlen(str1) >= strlen(str2))
        {
            longest = str1;
            shortest = str2;
        }
        else
        {
            longest = str2;
            shortest = str1;
        }

        while (i < strlen(shortest))
        {
            if (longest[i + edits] == shortest[i])
            {
                i += 1;
            }
            else if (longest[i + edits] != shortest[i])
            {
                edits += 1;
                if (edits > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
}