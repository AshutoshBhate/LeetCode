# My Approach : (Pre-order DFS Traversal with Level Tracking)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def helper(self, root, curr_level):
        if root == None:
            return

        if curr_level > self.level and (root.left or root.right):
            if root.left:
                self.leftMost = root.left.val
            else:
                self.leftMost = root.right.val
                
            self.level += 1

        self.helper(root.left, curr_level + 1)
        self.helper(root.right, curr_level + 1)



    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.leftMost = root.val
        self.level = 0
        self.curr_level = 0

        self.helper(root, self.curr_level + 1)

        return self.leftMost


# Gemini's Approach :

# Intuition for BFS (Right-to-Left Level-Order Traversal):
# Process nodes level by level. By enqueueing the right child before the left child,
# each level is visited from right to left. The very last node dequeued is guaranteed
# to be the bottom-leftmost node of the entire tree.

from collections import deque
from typing import Optional

class SolutionBFS:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue = deque([root])
        node = root
        while queue:
            node = queue.popleft()
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)
        return node.val


# Intuition for DFS (Pre-order Traversal tracking Max Depth):
# Traverse the tree left child first, then right child. Whenever we visit a depth greater
# than the maximum depth recorded so far, the current node is the leftmost node at that new depth.
# Update the recorded value and max depth.

class SolutionDFS:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        max_depth = -1
        leftmost_val = root.val

        def dfs(node, depth):
            nonlocal max_depth, leftmost_val
            if not node:
                return

            if depth > max_depth:
                max_depth = depth
                leftmost_val = node.val

            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        dfs(root, 0)
        return leftmost_val