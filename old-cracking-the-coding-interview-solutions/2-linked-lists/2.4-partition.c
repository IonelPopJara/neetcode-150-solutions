#include "single-linked-list.h"
#include <stdio.h>

/* NOTE:
 * This problem can be solved without dummy nodes,
 * but they simplify  the job a lot.
 */

NODE* partition(NODE* head, int x) {
    if (head == NULL) return head;

    NODE left = {0, NULL};  // Dummy Node
    NODE right = {0, NULL}; // Dummy Node
    NODE* l_tail = &left;
    NODE* r_tail = &right;

    NODE* current = head;

    while (current) {
        if (current->data >= x) {
            // Append to right
            r_tail->pNext = current;
            r_tail = r_tail->pNext;

        } else {
            // Append to left
            l_tail->pNext = current;
            l_tail = l_tail->pNext;
        }
        current = current->pNext;
    }

    l_tail->pNext = right.pNext;
    r_tail->pNext = NULL;

    return left.pNext;
}

NODE* partition_old(NODE* head, int x) {
    NODE* current = head;

    NODE* left = NULL;
    NODE* l_tail = left;

    NODE* right = NULL;
    NODE* r_tail = right;

    while (current != NULL) {
        if (current->data >= x) {
            // Insert in the RIGHT list
            printf("Insert %d in the RIGHT list\n", current->data);
            if (r_tail == NULL) {
                printf("\tThe RIGHT list is empty\n");
                // First item of the list
                right = current;
                // Why doesn't r_tail change when right changes??
                r_tail = current;
            }
            else {
                printf("\t%d->pNext = %d\n", r_tail->data, current->data);
                r_tail->pNext = current;
                r_tail = r_tail->pNext;
            }
            /*r_tail->pNext = NULL;*/
        }
        else {
            // Insert in the LEFT list
            printf("Insert %d in the LEFT list\n", current->data);
            if (l_tail == NULL) {
                printf("\tThe LEFT list is empty\n");
                // First item of the list
                left = current;
                l_tail = current;
            }
            else {
                printf("\t%d->pNext = %d\n", l_tail->data, current->data);
                l_tail->pNext = current;
                l_tail = l_tail->pNext;
            }
        }
        current = current->pNext;
    }

    if (left != NULL && right != NULL) {
        l_tail->pNext = right;
        r_tail->pNext = NULL;
        return left;
    } else if (left == NULL) {
        return right;
    } else {
        return left;
    }
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
