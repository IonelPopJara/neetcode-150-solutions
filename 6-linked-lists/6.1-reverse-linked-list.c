// @leet start
#include<stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL || !head->next) {
        return head;
    }

    struct ListNode* back = NULL;
    struct ListNode* front = head;

    while(front) {
        // reverse the two nodes
        struct ListNode* temp = front->next;
        front->next = back;
        back = front;
        front = temp;
    }

    return back;
}
// @leet end
