class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
    
    def printList(self):
        if not self.head:
            print("Empty list")
        else:
            current_node = self.head
            while current_node.next:
                print(f"{current_node.val} -> ", end=" ")
                current_node = current_node.next
            print(f"{current_node.val}", end=" ")
            print("")

class Solution:
    def deleteMiddleNode(self, node : Node) -> bool:
        if node is None or node.next is None:
            return False
        next_node = node.next
        node.val = next_node.val
        node.next = next_node.next
        return True

# Test code
linked_list = LinkedList()
linked_list.append(1)
linked_list.append(5)
linked_list.append(9)
linked_list.append(12)

print("Original")
linked_list.printList()

current = linked_list.head

while current:
    if current.val == 9:
        break
    current = current.next
    
# print("List from the node")
# print(current)

sol = Solution()
val = sol.deleteMiddleNode(current)

print("Final")
linked_list.printList()