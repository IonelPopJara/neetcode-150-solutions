#include "single-linked-list.h"
#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(NODE* head) {
    NODE* slow = head;
    NODE* fast = head;

    // Find the middle of the list (slow)
    while(fast && fast->pNext) {
        /*printf("\tSlow: %d\n", slow->data);*/
        /*printf("\tFast: %d\n", fast->data);*/
        fast = fast->pNext->pNext;
        slow = slow->pNext;
    }

    // Reverse the second half of the list
    NODE* prev = NULL;
    while(slow) {
        NODE* tmp = slow->pNext;
        slow->pNext = prev;
        prev = slow;
        slow = tmp;
    }

    // Check palindrome
    NODE* left = head;
    NODE* right = prev;
    while(right) {

        if (left->data != right->data) {
            return false;
        }

        left = left->pNext;
        right = right->pNext;

    }

    return true;
}

int main() {

    // Test case 1
    int input_1[] = {1, 2, 2, 1}; // Expected output: true

    NODE* list_1 = NULL;
    for (int i = 0; i < 4; i++) {
        list_1 = insert_node(list_1, input_1[i]);
    }

    printf("Test case 1:\n");
    printf("\tInput ");
    print_list(list_1);
    printf("\tIs Palindrome? %b\n", is_palindrome(list_1));

    // Test case 2
    int input_2[] = {1, 2}; // Expected output: false

    NODE* list_2 = NULL;
    for (int i = 0; i < 2; i++) {
        /*printf("Input 2: %d\n", input_2[i]);*/
        list_2 = insert_node(list_2, input_2[i]);
    }

    printf("Test case 2:\n");
    printf("\tInput ");
    print_list(list_2);
    printf("\tIs Palindrome? %b\n", is_palindrome(list_2));

    // Free allocated memory
    list_1 = delete_list(list_1);
    list_2 = delete_list(list_2);
}
