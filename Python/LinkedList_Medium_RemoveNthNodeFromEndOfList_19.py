# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        ptr = head
        count = 0

        while ptr != None:
            count += 1
            ptr = ptr.next
        
        to_remove = count - n + 1
        temp = head
        ptr = None

        while to_remove > 1:
            ptr = temp
            temp = temp.next
            to_remove -= 1

        if ptr != None:
            ptr.next = temp.next
            temp.next = None
            return head
        else:
            return temp.next