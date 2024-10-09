class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        
        new_node = Node(data)
        
        if not self.head:
            self.head = new_node
        else:
            current_node = self.head
            while current_node.next:
                current_node = current_node.next
            current_node.next = new_node
    
    def printList(self):
        if not self.head:
            print("Empty list")
        else:
            current_node = self.head
            while current_node.next:
                print(f'{current_node.data} -> ', end=" ")
                current_node = current_node.next
            print(f'{current_node.data}', end=" ")
            print("")

class Solution:
    def removeDuplicates(self, head : Node) -> None:
        hash_table = []
        previous_node = None
        current_node = head
        while current_node:
            if current_node.data in hash_table:
                previous_node.next = current_node.next
            else:
                hash_table.append(current_node.data)
                previous_node = current_node
            current_node = current_node.next
    
# Test code
linked_list = LinkedList()
linked_list.append(4)
linked_list.append(5)
linked_list.append(2)
linked_list.append(10)
linked_list.append(3)
linked_list.append(4)
linked_list.append(5)
linked_list.append(3)
linked_list.append(10)

print("Original")
linked_list.printList()

# 4 ->  3 ->  5 ->  2 ->  10 ->  4 ->  5

sol = Solution()
sol.removeDuplicates(linked_list.head)

print("After removing duplicates")
linked_list.printList()
