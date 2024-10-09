#pragma once
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *pNext;
} NODE;

NODE* create_random_list(int n_items);

NODE* insert_node(NODE* head, int data);

NODE* delete_node(NODE* head, int data);

NODE* delete_list(NODE* head);

void print_list(NODE* head);

