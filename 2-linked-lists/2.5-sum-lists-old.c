#include "single-linked-list.h"
#include <stdio.h>

unsigned long find_n_digits(unsigned long num) {
    // NOTE: Looks stupid but it is more efficient than a lot of other functions
    if (num < 10) {
        return 1;
    } else if (num < 100) {
        return 2;
    } else if (num < 1000) {
        return 3;
    } else if (num < 10000) {
        return 4;
    } else if (num < 100000) {
        return 5;
    } else if (num < 1000000) {
        return 6;
    } else if (num < 10000000){
        return 7;
    } else if (num < 100000000){
        return 8;
    } else if (num < 1000000000){
        return 9;
    } else if (num < 10000000000){
        return 10;
    } else if (num < 100000000000){
        return 11;
    } else if (num < 1000000000000){
        return 12;
    } else if (num < 10000000000000){
        return 13;
    } else if (num < 100000000000000){
        return 14;
    } else if (num < 1000000000000000){
        return 15;
    } else if (num < 10000000000000000){
        return 16;
    } else if (num < 100000000000000000){
        return 17;
    } else {
        return 18;
    }
}

int pow_10(int x) {
    int res = 1;
    for (int i = 0; i < x; i++) {
        res *= 10;
    }

    return res;
}

NODE* sum_lists(NODE* list_1, NODE* list_2) {
    NODE* result = NULL;
    int carry = 0;
    while (list_1 != NULL || list_2 != NULL) {
        int sum = 0;

        if (list_1 != NULL) {
            sum += list_1->data;
            list_1 = list_1->pNext;
        }

        if (list_2 != NULL) {
            sum += list_2->data;
            list_2 = list_2->pNext;
        }

        sum += carry;
        carry = sum / 10;

        result = insert_node(result, sum % 10);
    }

    if (carry != 0) {
        result = insert_node(result, carry);
    }

    return result;
}

NODE* sum_lists_2(NODE* list_1, NODE* list_2) {
    NODE* result = NULL;

    printf("Check list 1:\n");
    unsigned long long int unit_counter = 1;
    unsigned long num_1 = 0;
    while (list_1 != NULL) {
        printf("\tdigit: %d | unit: %llu\n", list_1->data, unit_counter);
        num_1 += (list_1->data * unit_counter);
        unit_counter *= 10;
        list_1 = list_1->pNext;
    }
    printf("First number: %lu\n", num_1);

    unit_counter = 1;
    int num_2 = 0;
    while (list_2 != NULL) {
        num_2 += (list_2->data * unit_counter);
        unit_counter *= 10;
        list_2 = list_2->pNext;
    }
    printf("Second number: %d\n", num_2);

    int total = num_1 + num_2;
    int n_digits = find_n_digits(total);
    /*printf("Sum: %d\n", total);*/

    for (int i = 0; i < n_digits; i++) {
        int current = (total % pow_10(i + 1)) / pow_10(i);
        /*printf("Current: %d\n", current);*/
        result = insert_node(result, current);
    }

    return result;
}

int main() {

    // Input 1
    int input_1[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};

    // Input 2
    int input_2[] = {5,6,4};

    // Expected output: [6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]

    // create list 1
    NODE* list_1 = NULL;
    for (int i = 0; i < 31; i++) {
        /*printf("Input 1: %d\n", input_1[i]);*/
        list_1 = insert_node(list_1, input_1[i]);
    }

    // Print list 1
    print_list(list_1);

    NODE* list_2 = NULL;
    for (int i = 0; i < 3; i++) {
        /*printf("Input 2: %d\n", input_2[i]);*/
        list_2 = insert_node(list_2, input_2[i]);
    }

    // Print list 2
    print_list(list_2);

    // Sum Lists
    NODE* result = sum_lists(list_1, list_2);
    printf("Result ");
    print_list(result);

    // Free allocated memory
    list_1 = delete_list(list_1);
    list_2 = delete_list(list_2);
    /*result = delete_list(result);*/
}
