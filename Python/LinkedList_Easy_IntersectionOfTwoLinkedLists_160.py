#Better Approach : 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def collisionPoint(self, longer, shorter, difference) -> ListNode:
        while difference > 0:
            longer = longer.next
            difference -= 1

        while longer != None and shorter != None:
            if longer == shorter:
                return longer
            else:
                longer = longer.next
                shorter = shorter.next  

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        ptr_1 = headA
        count_A = 0
        while ptr_1 != None:
            count_A += 1
            ptr_1 = ptr_1.next

        ptr_2 = headB
        count_B = 0
        while ptr_2 != None:
            count_B += 1
            ptr_2 = ptr_2.next

        if count_A > count_B:
            return self.collisionPoint(headA, headB, count_A - count_B)
        else:
            return self.collisionPoint(headB, headA, count_B - count_A)
        
# Optimal Approach : 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        ptr_1 = headA
        ptr_2 = headB

        if headA == None or headB == None:
            return None
        
        while ptr_1 != ptr_2:
            ptr_1 = ptr_1.next
            ptr_2 = ptr_2.next

            if ptr_1 == ptr_2:
                return ptr_1

            if ptr_1 == None:
                ptr_1 = headB
            if ptr_2 == None:
                ptr_2 = headA
        
        return ptr_1
