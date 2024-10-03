// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strNode {
    struct strNode *next;
    char* data;
} STRNODE;

typedef struct node {
    struct node *next;
    char data;
} NODE;

typedef struct strStack {
    int size;
    STRNODE* top;
} STRSTACK;

typedef struct stack {
    int size;
    NODE* top;
} STACK;

STACK* initStack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

STRSTACK* initStrStack() {
    STRSTACK* stack = (STRSTACK*)malloc(sizeof(STRSTACK));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void pushStack(STACK* stack, char c) {
    // Create a node with the new data
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = c;
    // Link the new node to the previous node in the stack
    newNode->next = stack->top;
    // Make the new node the head of the stack
    stack->top = newNode;
    stack->size += 1;
}

void pushStrStack(STRSTACK* stack, char* c) {
    // Create a node with the new data
    STRNODE* newNode = (STRNODE*)malloc(sizeof(STRNODE));
    newNode->data = c;
    // Link the new node to the previous node in the stack
    newNode->next = stack->top;
    // Make the new node the head of the stack
    stack->top = newNode;
    stack->size += 1;
}

char popStack(STACK* stack) {
    // If the stack is empty
    if (stack->top == NULL) {
        return '\0';
    }

    // Get the popped node
    NODE* popped = stack->top;

    // Re-link the pointer
    stack->top = stack->top->next;

    stack->size -= 1;
    return popped->data;
}

char* popStrStack(STRSTACK* stack) {
    // If the stack is empty
    if (stack->top == NULL) {
        return NULL;
    }

    // Get the popped node
    STRNODE* popped = stack->top;

    // Re-link the pointer
    stack->top = stack->top->next;

    stack->size -= 1;
    return popped->data;
}

void printStack(STACK* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Printing stack of size %d...\n", stack->size);
    NODE* current = stack->top;
    while (current) {
        printf("    %c\n", current->data);
        current = current->next;
    }
    printf("End of stack\n");
}

void printStrStack(STRSTACK* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Printing string stack of size %d...\n", stack->size);
    STRNODE* current = stack->top;
    while (current) {
        printf("    %s\n", current->data);
        current = current->next;
    }
    printf("End of str stack\n");
}

char* stringifyStack(STACK* stack) {
    int size = stack->size;
    char* stringified = (char*)malloc((size * sizeof(char)) + 1);
    NODE* current = stack->top;
    int i = size - 1;
    while(current) {
        stringified[i--] = current->data;
        current = current->next;
    }

    stringified[size] = '\0';
    return stringified;
}

char** stringifyStrStack(STRSTACK* stack) {
    int size = stack->size;
    char** stringified = (char**)malloc(size * sizeof(char*));

    STRNODE* current = stack->top;
    char** tmp = stringified;
    for (int i = 0; i < size; i++) {
        stringified[i] = NULL;
    }
    while (current) {
        *tmp = (char*)malloc(sizeof(char) * 20);
        strcpy(*tmp, current->data);
        tmp++;
        current = current->next;
    }

    tmp = stringified;
    int i = 0;

    return stringified;
}

void permutate(int n_opened, int n_closed, STACK* stack, STRSTACK* strStack) {
    // Can't add any more parenthesis
    if (n_closed == 0 && n_closed == 0) {
        // TODO: add final combination
        char* final = stringifyStack(stack);
        pushStrStack(strStack, final);
        /*printStrStack(strStack);*/
        /*printf("Final: %s\n", final);*/
        return;
    }

    // Add opened parenthesis
    if (n_opened > 0) {
        pushStack(stack, '(');
        permutate(n_opened - 1, n_closed, stack, strStack);
        popStack(stack);
    }

    // Add closed parenthesis
    if (n_closed > n_opened) {
        pushStack(stack, ')');
        permutate(n_opened, n_closed - 1, stack, strStack);
        popStack(stack);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    STRSTACK* strStack = initStrStack();
    STACK* stack = initStack();

    permutate(n, n, stack, strStack);

    *returnSize = strStack->size;
    printStrStack(strStack);
    char** result = stringifyStrStack(strStack);

    free(stack);

    return result;
}
// @leet end
