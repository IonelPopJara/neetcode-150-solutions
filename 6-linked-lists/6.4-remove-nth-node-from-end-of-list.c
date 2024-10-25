// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    // Create a dummy node that points to the start of the list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    // Assign the fast pointer to the head of the list
    struct ListNode* fast = head;

    // Assign the slow pointer to the dummy node
    struct ListNode* slow = dummy;

    // Traverse to the list and update pointers according to our needs
    // idk how else to explain it, it's pretty self explanatory
    int counter = 0;
    while (fast) {
        if (counter < n) {
            counter++;
        } else {
            slow = slow->next;
        }

        fast = fast->next;
    }

    // Remove the node
    slow->next = slow->next->next;

    // Fix the start of the list in case we deleted the first node
    head = dummy->next;

    // Free the dummy node
    free(dummy);

    return head;
}
// @leet end
