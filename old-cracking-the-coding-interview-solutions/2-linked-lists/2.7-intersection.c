#include "single-linked-list.c"

NODE *getIntersectionNode(NODE *headA, NODE *headB) {
    NODE* curra = headA;
    NODE* currb = headB;

    while (curra != currb) {
        curra = curra != NULL ? curra->pNext : headB;
        currb = currb != NULL ? currb->pNext : headA;
    }

    return curra;
}

int main() {
    // I was too lazy to write test code for this one
    // I just did it in LeetCode
}


//////////////////// FIRST ATTEMPT - NOT GOOD ENOUGH BUT IT WORKED ////////////////////////
/*struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {*/
/*    char simple_hash[10000000] = {0};*/
/**/
/*    printf("A:\n");*/
/*    while (headA) {*/
/*        int addr = (int)headA; // Get the address*/
/*        printf("\tdata: %d | addr(hex): %x | addr(dec): %d | addr(int): %d\n", headA->val, headA, headA, addr);*/
/*        simple_hash[addr] = 1;*/
/*        headA = headA->next;*/
/*    }*/
/**/
/*    // for (int i = 0; i < 1000; i++) {*/
/*    //     printf("simple_hash[%d] = %d\n", i, simple_hash[i]);*/
/*    // }*/
/**/
/*    printf("B:\n");*/
/*    while (headB) {*/
/*        int addr = (int)headB; // Get the address*/
/*        if (simple_hash[addr] == 1) {*/
/*            return headB;*/
/*        }*/
/*        printf("\tdata: %d | addr(hex): %x | addr(dec): %d\n", headB->val, headB, headB);*/
/*        headB = headB->next;*/
/*    }*/
/**/
/*    return NULL;*/
/*}*/
//////////////////// FIRST ATTEMPT - NOT GOOD ENOUGH BUT IT WORKED ////////////////////////
