// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void printList(struct ListNode* head, const char* name) {
    printf("%s List:", name);
    struct ListNode* current = head;
    while (current) {
        printf(" %d ->", current->val);
        current = current->next;
    }
    printf(" NULL\n");
}
void reorderList(struct ListNode* head) {
    // Find the middle of the list
    // Slow is our middle pointer
    struct ListNode* middle = head;
    struct ListNode* end = head->next;

    while(end && end->next) {
        middle = middle->next;
        end = end->next->next;
    }

    // Reverse the list from the middle onwards
    struct ListNode* front = middle->next;
    struct ListNode* back = NULL;
    middle->next = NULL;

    while (front) {
        struct ListNode* tmp = front->next;
        front->next = back;
        back = front;
        front = tmp;
    }


    // Merge the two lists
    struct ListNode* first = head;
    struct ListNode* second = back;
    while (second) {
        struct ListNode* tmp1 = first->next;
        struct ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}
// @leet end
