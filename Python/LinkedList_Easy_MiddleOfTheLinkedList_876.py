# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tortoise = head
        rabbit = head

        while rabbit != None and rabbit.next != None:
            tortoise = tortoise.next
            rabbit = rabbit.next.next
        
        return tortoise

        