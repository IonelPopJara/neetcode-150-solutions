#include "single-linked-list.h"

NODE* partition(NODE* head, int x) {

    return head;
}

int main() {
    // create list
    NODE* head = NULL;

    head = insert_node(head, 3);
    head = insert_node(head, 5);
    head = insert_node(head, 8);
    head = insert_node(head, 5);
    head = insert_node(head, 10);
    head = insert_node(head, 2);
    head = insert_node(head, 1);

    // Print original list
    print_list(head);

    head = partition(head, 5);

    // Print list after partition
    print_list(head);

    // Free allocated memory
    head = delete_list(head);
}
