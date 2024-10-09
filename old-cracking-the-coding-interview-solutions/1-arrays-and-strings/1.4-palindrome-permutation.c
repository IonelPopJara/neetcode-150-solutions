#include <stdio.h>
#include <assert.h>

/**
 * Problem description:
 * 
 * Given a string, write a function to check if it is a permutation
 * of a palindrome. A palindrome is a word or phrase that is the same
 * forwards and backwards. A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 * 
 * My idea:
 * 
 * For a palindrome to be considered a palindrome it has to have the
 * same pairs of letters + 1 extra letter in the middle. Unless the
 * length is even, in that case there can not be any extra letter.
 * 
 * For example:
 * 
 * tac o cat -> 2*t + 2*a + 2*c + o
 * ka y ak -> 2*k + 2*a + y
 * 
 * The order of the letters is important, but because we are given a
 * permutation of the palindrome, we don't care about it.
 * 
 * Therefore, my solution would be to create a hash-map that stores
 * the counters for the letters, after that, we can iterate through
 * the counters and see if there are any odd numbers depending on
 * the length of the word.
 * 
 * Note: we don't care about spaces either. I'll make a function
 * to ignore them when counting the length of the array.
 * 
 * For example:
 * 
 * abba -> length is 4, even
 * [a:2, b:2] -> therefore, there should be no odd counters
 * 
 * taco cat -> length is 7, odd
 * [a:2, c: 2, o: 1, t: 2] -> therefore, there should be only one odd counter
 * 
 * tacatacat -> length is 9, odd
 * [t: 3, a: 4, c: 2] -> therefore, there should be only one odd counter
 * 
 * tacoccat -> length is 8, even
 * [a:2, c:3, o:1, t:2] -> there should be no odd counters, but there are 2
 * 
 * aaaaaa -> even
 * [a:6] -> par & no odd counters => palindrome
 * 
 * aabaa -> odd
 * [a:2, b:1] odd & one odd counter => palindrome
 * 
 * tactocoa
 * tacoocat
 * 
 * 
*/

/**
 * Helper function that returns the length of
 * the string without counting spaces
*/
int trimmedLength(char* str);

/**
 * Helper function that converts the string
 * to lowercase letters
*/
void toLowerCase(char* str);

/**
 * Main solution
*/
int solution(char* str);

int main()
{
    char test1[] = "Tact Coa";
    assert(solution(test1) == 1);
    printf("Test 1 passed :)\n");

    char test2[] = "Tacto Coa";
    assert(solution(test2) == 1);
    printf("Test 2 passed :)\n");

    char test3[] = "tacoccat";
    assert(solution(test3) == 0);
    printf("Test 3 passed :)\n");

    char test4[] = "aba";
    assert(solution(test4) == 1);
    printf("Test 4 passed :)\n");

    char test5[] = "abba";
    assert(solution(test5) == 1);
    printf("Test 5 passed :)\n");

    char test6[] = "abcba";
    assert(solution(test6) == 1);
    printf("Test 6 passed :)\n");

    char test7[] = "";
    assert(solution(test7) == 1);
    printf("Test 7 passed :)\n");

    char test8[] = "aaacbbb";
    assert(solution(test8) == 0);
    printf("Test 8 passed :)\n");

    return 0;
}

int solution(char* str)
{
    toLowerCase(str);

    int strLength = trimmedLength(str);

    // Since I'm not using booleans, 1 means it's odd, 0 means it's even
    int isOdd = strLength % 2 == 0 ? 0 : 1;

    // Create a 50 byte array to account for 27 different ascii lowercase letters
    int charCounter[50]; // 50 just in case

    // Initialize the counter;
    for (int i = 0; i < 50; i++)
    {
        charCounter[i] = 0;
    }

    // Iterate through the string
    while (*str != '\0')
    {
        // If it's not a space
        if (*str != ' ')
        {
            // Add it to the counter
            // char - 97 to map the
            // characters from 0 to 27
            charCounter[*str - 97] += 1;
        }
        *str++;
    }

    int oddCounter = 0;

    for (int i = 0; i < 50; i++)
    {
        if (charCounter[i] % 2 != 0)
        {
            oddCounter += 1;
        }
    }

    return isOdd == oddCounter;
}

int trimmedLength(char* str)
{
    char* iterator = str;
    int length = 0;
    while(*iterator != '\0')
    {
        if(*iterator != ' ')
        {
            length++;
        }
        iterator++;
    }

    return length;
}

void toLowerCase(char* str)
{
    while (*str != '\0')
    {
        // If we encounter a uppercase and not a space
        if ((int)*str <= 90 && *str != ' ')
        {
            // Convert it to lowercase by adding 32
            int newChar = (int)*str + 32;
            *str = newChar;
        }
        str++;
    }
}