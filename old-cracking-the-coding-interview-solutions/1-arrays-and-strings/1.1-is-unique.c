#include <stdio.h>
#include <string.h>
#include <assert.h>

int solution(char* input);

/**
 * Main function for testing purposes
*/
int main()
{
    char* testString = "bomb";
    assert(solution(testString) == 0); // Not unique
    printf("Test 1 passed :)\n");

    char* testString2 = "alo";
    assert(solution(testString2) == 1); // Unique
    printf("Test 2 passed :)\n");

    char* testString3 = "";
    assert(solution(testString3) == 1); // Unique
    printf("Test 3 passed :)\n");

    char* testString4 = "brodd";
    assert(solution(testString4) == 0); // Not unique
    printf("Test 4 passed :)\n");

    printf("All tests passed!\n");

    return 0;
}

/**
 * This implementation asumes that all the characters are lowercase ascii letters.
 * 
 * Note: 0b in front of a number represents a binary number (0b1 = 1, 0b11 = 3)
 * 
 * The simple way to think about this implementation is that any time we encounter a character
 * for the first time, we can add that to a binary number whose max length will be 128.
 * Then, if we encounter the same character again, we just check if it exists doing an & operation.
 * 
 * For example: "aba"
 * 
 * We first define a checker and initialize it as 0
 * checker = 0
 * 
 * Then we check 'a'
 * By doing input[i] - 'a' we are maping the ASCII values to start from 0. ('a' = 97)
 * 
 * int val = 0
 * int shifted = 1 << 0
 * -> shifted = 0b1
 * 
 * int result = checker & shifted -> 0b0 & 0b1
 *    0b0
 *  & 0b1
 *  -----
 * -> 0b0
 * 
 * Since result is not greater than 0, we don't go into the if-statement
 * 
 * checker = checker | result -> 0b0 | 0b1
 *    0b0
 *  | 0b1
 *  -----
 * -> 0b1
 * 
 * Then we check 'b'
 * The process is similar the previous step and we end up with
 * checker = 0b11
 * 
 * Finally we check the last 'a'
 * 
 * checker = 0b11
 * int val = 0
 * int shifted = 0b1
 * 
 * int result = checker & shifted -> 0b11 & 0b1
 *    0b11
 *  & 0b01
 *  ------
 * -> 0b01
 * 
 * Since result is greater than 0, we know that a character has been repeated,
 * and we return 0, a.k.a., False
 * 
*/
int solution(char* input)
{
    if (strlen(input) <= 1)
    {
        return 1;
    }

    int checker = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        int val = (int)input[i] - 'a';
        int shifted = 1 << val;

        int result = checker & shifted;

        if (result > 0)
        {
            return 0;
        }

        checker = checker | shifted;
    }

    return 1;
}
