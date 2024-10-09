#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Problem description:
 *
 * Implement a method to perform basic string compression using the counts
 * of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
 * "compressed" string would not become smaller than the original string, your method should return
 * the original string. You can assume the string has only uppercase and lowercase letters (a - z).
 *
 * My idea:
 *
 * I can iterate through the array as I'm building the string, once I find a new letter, I change characters.
 *
 * Since it doesn't specify, I'm going to assume that 'a' is different than 'A', therefore AAaabc = 2A2abc.
 */

void compressString(char *inputString, char outputBuffer[]);

int main()
{
    char *test = "aabcccccaaa";
    char outputString[strlen(test) * 2];

    compressString(test, outputString);

    assert(strcmp(outputString, "a2b1c5a3") == 0);

    printf("Compressed String: %s\n", outputString);
    printf("Test 1 passed :)\n");

    char *test2 = "Aabcd";
    char outputString2[strlen(test2) * 2];

    compressString(test2, outputString2);

    assert(strcmp(outputString2, "Aabcd") == 0);

    printf("Compressed String: %s\n", outputString2);
    printf("Test 2 passed :)\n");
    return 0;
}

void compressString(char *inputString, char outputBuffer[])
{
    int currentCount = 1;
    int outputBufferCount = 0;
    char currentCharacter = inputString[0];
    for (int i = 1; i < strlen(inputString); i++)
    {
        // If the characters are different, for example aa|b (we're comparing a and b)
        if (currentCharacter != inputString[i])
        {

            char countString[10];
            sprintf(countString, "%d", currentCount);

            outputBuffer[outputBufferCount++] = currentCharacter;

            for (int j = 0; j < strlen(countString); j++)
            {
                outputBuffer[outputBufferCount++] = countString[j];
            }
            currentCharacter = inputString[i];
            currentCount = 1;
        }
        else
        {
            currentCount++;
        }
    }

    // To account for the last character
    char countString[10];
    sprintf(countString, "%d", currentCount);

    outputBuffer[outputBufferCount++] = currentCharacter;

    for (int j = 0; j < strlen(countString); j++)
    {
        outputBuffer[outputBufferCount++] = countString[j];
    }

    outputBuffer[outputBufferCount] = '\0';

    if (strlen(inputString) < strlen(outputBuffer))
    {
        strcpy(outputBuffer, inputString);
    }
}
