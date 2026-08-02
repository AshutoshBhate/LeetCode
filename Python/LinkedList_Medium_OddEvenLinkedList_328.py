# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head


        counter = head.next
        odd = head
        even = head.next

        while even != None and even.next != None and odd != None and odd.next != None:

            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        odd.next = counter
    
        return head
        