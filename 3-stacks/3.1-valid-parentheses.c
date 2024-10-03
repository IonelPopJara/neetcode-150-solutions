#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct stack {
    char data[MAX_SIZE];
    int top;
} STACK;

void push(STACK *stack, char c) {
    if (stack->top >= MAX_SIZE) {
        // Stack full
        printf("Stack full. Can't push!\n");
        return;
    }

    printf("Pushing %c ...\n", c);

    stack->data[stack->top] = c;
    stack->top += 1;
}

char pop(STACK* stack) {
    if (stack->top <= 0) {
        // Stack empty
        printf("Stack empty. Can't pop!\n");
        return '\0';
    }

    stack->top -= 1;
    char popped = stack->data[stack->top];

    stack->data[stack->top] = '\0';

    printf("Popping %c ...\n", popped);

    return popped;
}

bool isValid(char* s) {
    STACK stack = {0};

    while(*s != '\0') {
        if (*s == '{' || *s == '[' || *s == '(') {
            push(&stack, *s);
        }
        else {
            char popped = pop(&stack);
            if ((popped == '\0') || (popped == '{' && *s != '}') ||
            (popped == '[' && *s != ']') || 
            (popped == '(' && *s != ')')) {
                return false;
            }
        }
        s++;
    }

    if (stack.top == 0) {
        return true;
    } else {
        return false;
    }
}
