# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 86. Partition List

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left = ListNode()
        right = ListNode()
        l_tail = left
        r_tail = right

        current = head
        while current:
            if current.val >= x:
                # Append to the right list
                r_tail.next = current
                r_tail = r_tail.next
            else:
                # Append to the left list
                l_tail.next = current
                l_tail = l_tail.next

            current = current.next

        l_tail.next = right.next
        r_tail.next = None

        return left.next

