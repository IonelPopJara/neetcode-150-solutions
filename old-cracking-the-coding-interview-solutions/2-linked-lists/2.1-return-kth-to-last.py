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
                print(f"{current_node.data} -> ", end=" ")
                current_node = current_node.next
            print(f"{current_node.data}", end=" ")
            print("")


class Solution:
    def returnKthToLast(self, head: Node, k: int) -> int:
        # A B C | k = 3
        counter = 0
        last = head
        while last and counter < k - 1:
            last = last.next
            counter += 1

        if counter < k - 1 or not last:
            print("Error! List is not long enough")
            return None

        current = head
        while last.next:
            current = current.next
            last = last.next

        return current.data


# Test code
linked_list = LinkedList()
linked_list.append(1)
linked_list.append(2)
linked_list.append(3)
linked_list.append(4)
linked_list.append(5)
linked_list.append(6)
linked_list.append(7)
linked_list.append(8)
linked_list.append(9)
linked_list.append(10)

print("Original")
linked_list.printList()

sol = Solution()
val = sol.returnKthToLast(linked_list.head, 11)

print(val)
