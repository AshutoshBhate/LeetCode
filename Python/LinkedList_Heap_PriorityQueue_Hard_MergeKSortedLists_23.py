# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []

        if not lists: 
            return None

        z = len(lists)

        for i, head in enumerate(lists):
            if head:
                heapq.heappush(heap, (head.val, i, head))

        dummy = ListNode(0, None)
        ptr = dummy

        while heap:
            node = heapq.heappop(heap)[2]
            dummy.next = node
            dummy = node

            if node.next:
                heapq.heappush(heap, (node.next.val, z, node.next))
                z += 1

        return ptr.next

        