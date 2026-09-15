from collections import deque, defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        parentMap = {}
        count = 0
        queue = deque()
        start_node = None
        queue.append(root)
        visited_map = defaultdict(int)
        
        while queue:
            if queue[0].val == start:
                start_node = queue[0]
            
            if queue[0].left:
                parentMap[queue[0].left] = queue[0]
                queue.append(queue[0].left)
            if queue[0].right:
                parentMap[queue[0].right] = queue[0]
                queue.append(queue[0].right)

            queue.popleft()

        queue.append(start_node)
        visited_map[start_node.val] = 1
        parentMap[root] = None

        while queue:
            queueSize = len(queue)

            for i in range(0, queueSize):
                currNode = queue[0]

                if parentMap[currNode] is not None and visited_map[parentMap[currNode].val] != 1:
                    queue.append(parentMap[currNode])
                    visited_map[parentMap[currNode].val] = 1
                if currNode.left is not None and visited_map[currNode.left.val] != 1:
                    queue.append(currNode.left)
                    visited_map[currNode.left.val] = 1
                if currNode.right is not None and visited_map[currNode.right.val] != 1:
                    queue.append(currNode.right)
                    visited_map[currNode.right.val] = 1

                queue.popleft()
            
            count += 1

        return count - 1

        

        

