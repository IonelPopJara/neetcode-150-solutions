// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct node {
    int index;
    int temperature;
    struct node* next;
} NODE;

typedef struct stack {
    int size;
    NODE* top;
} STACK;

STACK* initializeStack() {
    // Allocate memory
    STACK* stack = (STACK*)malloc(sizeof(STACK));

    // Initialize parameters
    stack->size = 0;
    stack->top = NULL;

    return stack;
}

void push(STACK* stack, int index, int temperature) {
    /*printf("Pushing %d with index %d\n", temperature, index);*/
    // Create a new node
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->index = index;
    newNode->temperature = temperature;

    // Re-link linked list
    newNode->next = stack->top;
    stack->top = newNode;

    // Update stack size
    stack->size++;
}

NODE* pop(STACK* stack) {
    // If the stack is empty
    if (stack->top == NULL) {
        return NULL;
    }

    // Get the first element of the stack
    NODE* popped = stack->top;
    /*printf("Popping %d with index %d\n", popped->temperature, popped->index);*/

    // Re-link liked list
    stack->top = stack->top->next;

    // Update stack size
    stack->size--;

    return popped;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    STACK* stack = initializeStack();
    *returnSize = temperaturesSize;
    int* answer = (int*)malloc(temperaturesSize * sizeof(int));

    for (int i = 0; i < temperaturesSize; i++) {
        // Initialize it to 0 in case there are no warmer days
        answer[i] = 0;
        int currentTemperature = temperatures[i];
        /*printf("Checking temperatures[%d] = %d\n", i, currentTemperature);*/

        // If the stack is empty, we just push it to the stack
        if (stack->size == 0) {
            push(stack, i, currentTemperature);
        } else {
            while (stack->top && stack->top->temperature < currentTemperature) {
                NODE* popped = pop(stack);
                /*printf("    popped->index: %d\n", popped->index);*/
                /*printf("    days: %d\n", i - popped->index);*/
                answer[popped->index] = i - popped->index;
            }

            push(stack, i, currentTemperature);
        }
    }

    return answer;
}
// @leet end

// Faster solution
int* dailyTemperaturesFast(int* temperatures, int temperaturesSize, int* returnSize) {

    int stack[temperaturesSize]; // Simple stack
    int top = -1; // Top variable for the stack

    *returnSize = temperaturesSize;
    int* answer = (int*)malloc(temperaturesSize * sizeof(int));

    for (int i = 0; i < temperaturesSize; i++) {
        // Initialize it to 0 in case there are no warmer days
        answer[i] = 0;

        // Get the current temperature
        int currentTemperature = temperatures[i];

        // If the stack is not empty, we pop until we find a smaller temperature
        while (top >= 0 && temperatures[stack[top]] < currentTemperature) {
            // stack[top] = popped index;
            int poppedIdx = stack[top--];
            answer[poppedIdx] = i - poppedIdx;
        }

        stack[++top] = i;
    }

    return answer;
}

