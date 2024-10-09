#include "single-linked-list.h"
#include <stdio.h>
#include <time.h>

NODE* create_random_list(int n_items) {
    // Seed for the random numbers
    srand(time(NULL));

    NODE* head = NULL;
    NODE* current = NULL;

    for (int i = 0; i < n_items; i++) {
        int data = rand() % 101;

        NODE* new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = data;
        new_node->pNext = NULL;

        // If it's the first node
        if (head == NULL) {
            head = new_node;
            current = head;
        // Otherwise
        } else {
            current->pNext = new_node;
            current = new_node;
        }
    }

    return head;
}

NODE* insert_node(NODE* head, int data) {
    // If the list is empty
    if (head == NULL) {
        NODE* new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = data;
        new_node->pNext = NULL;

        head = new_node;
        return head;
    }

    // If the list is not empty
    NODE* current = head;
    // Traverse until we find the last node
    while (current->pNext != NULL) {
        current = current->pNext;
    }

    // Allocate memory for the new node and initialize its data
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    if (new_node == NULL) {
        printf("ERROR! Memory allocation failed!\n");
        return head;
    }
    new_node->data = data;
    new_node->pNext = NULL;

    // Inser the node at the end of the list
    current->pNext = new_node;

    return head;
}

NODE* delete_node(NODE* head, int data) {
    if (head == NULL) {
        printf("WARNING! The list is empty\n");
        return head;
    }

    NODE* previous = NULL;
    NODE* current = head;

    while (current != NULL) {
        // If we want to delete a node
        if (current->data == data) {
            // If it's the first node
            if (previous == NULL) {
                head = current->pNext;
            } else {
                previous->pNext = current->pNext;
            }

            printf("Deleting node %d\n", data);

            free(current);
            return head;
        }

        previous = current;
        current = current->pNext;
    }

    printf("Node %d not found\n", data);

    return head;
}

NODE* delete_list(NODE* head) {
    if (head == NULL) {
        printf("WARNING! You are trying to delete an emtpy list\n");
        return head;
    }

    while (head != NULL) {
        NODE* current = head;
        head = head->pNext;
        free(current);
    }

    return head;
}

void print_list(NODE* head) {
    if (head == NULL) {
        printf("WARNING! You are trying to print an emtpy list\n");
        return;
    }

    printf("List: ");
    NODE* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->pNext != NULL) {

            printf(" -> ");
        }
        current = current->pNext;
    }
    printf("\n");
}

