#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * Problem description:
 * 
 * Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the
 * end to hold the additional characters,and that you are given
 * the "true" length of the string. (Note: If implementing in Java,
 * please use a character array so that you can perform this
 * operation in place.)
 * 
 * My idea:
 * 
 * The first solution I thought about would be iterating
 * through the array and when a space is encountered, shift
 * all the characters 2 spaces to the right to fit the '%20'.
 * However, this is not very efficient since its complexity
 * would be O(n^2)
 * 
 * The next solution I thought about involved creating a new
 * string with enough length called buffer, and iterate
 * through the first array. Whenever a regular character is
 * encountered, we just put it in the buffer, but when a space
 * is encountered we put the '%20'. This solution is more
 * efficient as its time complexity would be O(n*3), which is
 * just O(n). However, it's space complexity would also be O(n)
 * since we are creating a new array to store the characters.
 * 
 * I also thought about counting the number of spaces and
 * just shifting the characters but that doesn't click yet.
 * 
 * I'm pretty sure it can be done in place in O(n) but I'm a
 * bit lost. One good solution would be to implement a linked
 * list or a stack and just push elements there. But this is
 * an array question so that is out af scope.
 * 
 * So I'm gonna check the hints.
 * 
 * Now the solution clicked. If we just count the number of spaces,
 * multiply that by 2, and shift the characters from back to front
 * by that number, it should be done.
 * 
 * Example: (I'm using "-" to represent spaces)
 * "Mr-John-Smith" -> 2 spaces -> 2*2 -> shift 4 spaces to the right
 * "Mr---John---Smith"
 * As we can se, the string went from having length 13 to length 17
 * That is len(str) + shifted_spaces -> 13 + 4 = 17
 * 
 * We also have to replace the spaces while we shift
 * "Mr%20John%20Smith"
 * 
 * "Mr---John---Smith"
 * 
 * "Mr-John-Smith"
 * "Mr-John-Smit    h"
 * "Mr-John-Smi    th"
 * "Mr-John-Sm    ith"
 * "Mr-John-S    mith"
 * "Mr-John-    Smith"
 * - space detected
 * "Mr-John    -Smith"
 * - reduce number of shifted spaces by 2 -> 2
 * "Mr-Joh  n%20Smith"
 * "Mr-Jo  hn%20Smith"
 * "Mr-J  ohn%20Smith"
 * "Mr-  John%20Smith"
 * - space detected
 * - reduce number of shifted spaces by 2 -> 0
 * - exit the loop
 * "Mr%20John%20Smith"
 * 
*/

void solution(char* input_string, int string_length);

/**
 * Main function for testing purposes
*/

int main()
{
    char test_string_1[20] = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h', ' ', ' ', ' ', ' '};
    int length_1 = 13;

    solution(test_string_1, length_1);

    assert(strcmp(test_string_1,"Mr20\%John20\%Smith") == 0);
    printf("Test 1 passed :) | result: %s\n", test_string_1);

    char test_string_2[20] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    int lenght_2 = 12;

    solution(test_string_2, lenght_2);
    assert(strcmp(test_string_2,"Hello20\%World!") == 0);
    printf("Test 2 passed :) | result: %s\n", test_string_2);

    char test_string_3[10] = {' '};
    int lenght_3 = 1;

    solution(test_string_3, lenght_3);
    assert(strcmp(test_string_3,"20\%") == 0);
    printf("Test 3 passed :) | result: %s\n", test_string_3);

    return 0;
}

void solution(char* input_string, int string_length)
{
    // If the string is empty, we just return
    if (string_length < 1)
    {
        return;
    }

    int shifted_spaces = 0;

    // Count the number of spaces
    for (int i = 0; i < string_length; i++)
    {
        if (input_string[i] == ' ')
        {
            shifted_spaces ++;
        }
    }

    // Multiply the number of spaces by 2 to obtain
    // how many spaces we need to shift to the right
    shifted_spaces *= 2;

    /**
     * Iterate through the string until we run out
     * of spaces to shift. I added i >= 0 just as a
     * security measure. It is practically useless.
    */
    int i = string_length - 1;
    while (shifted_spaces > 0 && i >= 0)
    {
        // If the character is not a space
        if (input_string[i] != ' ')
        {
            // Move it to its corresponding place
            input_string[i + shifted_spaces] = input_string[i];
            // Replace the previous location with an empty space
            input_string[i] = ' '; // This is not necessary but it makes it cleaner in my opinion
        }
        // If the character is a space
        else
        {
            // Format 20% accordingly
            input_string[i + shifted_spaces] = '%';
            input_string[i + shifted_spaces - 1] = '0';
            input_string[i + shifted_spaces - 2] = '2';

            // Decrease the number of spaces we need to shift by 2
            shifted_spaces -= 2;
        }

        // Update the counter
        i--;
    }
}
