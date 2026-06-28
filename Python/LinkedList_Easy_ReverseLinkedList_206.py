# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None

        prev = None
        node = head
        temp = head.next

        while node.next != None:
            node.next = prev
            prev = node
            node = temp
            temp = temp.next
        
        node.next = prev

        return node

        