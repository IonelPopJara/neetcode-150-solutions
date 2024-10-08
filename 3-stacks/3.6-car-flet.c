#include <stdio.h>

// @leet start
void printArray(const char* str, int* input, int startIndex, int endIndex, const char* end) {
    printf("%s[", str);
    for (int i = startIndex; i < endIndex; i++) {
        printf("%d, ", input[i]);
    }
    printf("%d]%s", input[endIndex], end);
}

void merge(int* input, int startIndex, int middle, int endIndex, int* secondInput) {

    // Copy the data from the left and right subarrays into new temp arrays
    int n1 = middle - startIndex + 1;
    int n2 = endIndex - middle;

    int left[n1];
    int secondLeft[n1];
    for (int i = 0; i < n1; i++) {
        left[i] = input[startIndex + i];
        secondLeft[i] = secondInput[startIndex + i];
    }

    int right[n2];
    int secondRight[n2];
    for (int i = 0; i < n2; i++) {
        right[i] = input[middle + 1 + i];
        secondRight[i] = secondInput[middle + 1 + i];
    }

    // Iterate through the arrays and put them in the results sorted in the final array
    int i = 0;
    int j = 0;
    int k = startIndex;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            input[k] = left[i];
            secondInput[k] = secondLeft[i];
            i++;
        } else {
            input[k] = right[j];
            secondInput[k] = secondRight[j];
            j++;
        }
        k++;
    }

    // If there are any elements left in either of the arrays, put them in the final array
    while (i < n1) {
        input[k] = left[i];
        secondInput[k] = secondLeft[i];
        i++;
        k++;
    }

    while (j < n2) {
        input[k] = right[j];
        secondInput[k] = secondRight[j];
        j++;
        k++;
    }
}

void mergesort(int* input, int startIndex, int endIndex, int* secondInput) {
    if (startIndex >= endIndex) {
        return;
    }

    int middle = startIndex + (endIndex - startIndex) / 2; // Use this formula to avoid integer overflow
    mergesort(input, startIndex, middle, secondInput);
    mergesort(input, middle + 1, endIndex, secondInput);
    merge(input, startIndex, middle, endIndex, secondInput);

    return;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {

    // Custom merge sort to sort cars based on initial position and reoder the speed array to align with it
    int n = positionSize;
    mergesort(position, 0, n - 1, speed);

    // Initialize a stack to store the indexes
    float stack[n];
    int top = -1;

    // Iterate through the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        float backCarEta = (target - position[i]) / (float)speed[i];
        stack[++top] = backCarEta;

        // If the stack has more than two elements
        // And the back car is faster than the front car
        // They will become a fleet
        if (top > 0 && backCarEta <= stack[top - 1]) {
            // Pop the stack
            top--;
        }
    }

    return top + 1;
}
// @leet end
