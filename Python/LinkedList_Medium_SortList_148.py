# Optimal Approach : 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def findMiddle(self, head):
        slow = head
        fast = head.next

        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
        
        return slow

    def mergeHalves(self, leftNode, rightNode):
        ptr = ListNode()
        temp = ptr

        while leftNode != None and rightNode != None:
            if leftNode.val < rightNode.val:
                temp.next = leftNode
                temp = temp.next
                leftNode = leftNode.next
            else:
                temp.next = rightNode
                temp = temp.next
                rightNode = rightNode.next
            
        if leftNode == None:
            temp.next = rightNode
        else:
            temp.next = leftNode

        return ptr.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head == None or head.next == None:
            return head

        left = head
        middle = self.findMiddle(head)
        right = middle.next
        middle.next = None

        leftNode = self.sortList(left)
        rightNode = self.sortList(right)

        return self.mergeHalves(leftNode, rightNode)
        