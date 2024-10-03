// @leet start
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 10000

typedef struct stack {
    char* arr[MAX_SIZE];
    int top;
} STACK;

STACK* initializeStack() {
    STACK* rpnStack = (STACK*)malloc(sizeof(STACK));
    rpnStack->top = 0;
    return rpnStack;
}

void push(STACK* stack, char* val) {
    stack->arr[stack->top] = (char*)malloc(sizeof(char) * 5);
    stack->arr[stack->top] = val;
    stack->top++;
}

char* pop(STACK* stack) {
    if (stack->top <= 0) {
        return "0";
    }
    stack->top--;
    return stack->arr[stack->top];
}

void freeStack(STACK* stack, int size) {
    // FIX: doesn't free up memory properly
    free(stack);
}

int evalRPN(char** tokens, int tokensSize) {
    STACK* rpnStack = initializeStack();
    int result = 0;

    for (int i = 0; i < tokensSize; i++) {
        if ((strcmp(tokens[i], "+") != 0)
            && (strcmp(tokens[i], "-") != 0)
            && (strcmp(tokens[i], "*") != 0)
            && (strcmp(tokens[i], "/") != 0)) {
            // If it's not an operator, push it to the stack
            push(rpnStack, tokens[i]);
        } else {
            int result = 0;
            int first = atoi(pop(rpnStack));
            int second = atoi(pop(rpnStack));

            if (strcmp(tokens[i], "+") == 0) {
                result = second + first;
            } else if (strcmp(tokens[i], "-") == 0) {
                result = second - first;
            } else if (strcmp(tokens[i], "*") == 0) {
                result = second * first;
            } else {
                result = second / first;
            }

            char* resultStr = (char*)malloc(12 * sizeof(char)); // Enough space
            sprintf(resultStr, "%d", result);
            push(rpnStack, resultStr);
        }
    }

    char* popped = pop(rpnStack);

    return atoi(popped);
}
// @leet end
