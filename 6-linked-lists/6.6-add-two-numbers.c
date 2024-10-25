// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;

        // Insert the node in the result list
        // If the list is empty, we create a new one
        if (result == NULL) {
            result = (struct ListNode*)malloc(sizeof(struct ListNode));
            result->val = sum%10;
            result->next = NULL;
        }
        // Otherwise, we append at the end of the list
        else {
            struct ListNode* current = result;
            while (current->next) {
                current = current->next;
            }

            // Create a new node
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = sum%10;
            newNode->next = NULL;

            // Link the new node to the list
            current->next = newNode;
        }
    }
    return result;
}
// @leet end
