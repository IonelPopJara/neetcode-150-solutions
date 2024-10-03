#include <limits.h>
#define MAX_SIZE 100000

typedef struct {
    int stack[MAX_SIZE];
    int min_stack[MAX_SIZE];
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* newStack = (MinStack*)malloc(sizeof(MinStack));
    newStack->top = 0;
    return newStack;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[obj->top] = val;

    // Push to the min_stack
    if (obj->top <= 0) {
        obj->min_stack[obj->top] = val;
    } else {
        int min_item = obj->min_stack[obj->top - 1];
        if (val <= min_item) {
            min_item = val;
        }
        obj->min_stack[obj->top] = min_item;
    }

    obj->top++;
}

void minStackPop(MinStack* obj) {
    // Decrement top
    obj->top--;
    // Pop from the stack
    obj->stack[obj->top] = 0;
    // Pop from the min_stack
    obj->min_stack[obj->top] = INT_MAX;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
    int min_item = obj->min_stack[obj->top -1];
    return obj->min_stack[obj->top - 1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
