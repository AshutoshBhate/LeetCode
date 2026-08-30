# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    maxDepthNumber = float(-inf)

    def helper(self, root, currMax):
        if root == None:
            return

        self.maxDepthNumber = max(currMax, self.maxDepthNumber)

        self.helper(root.left, currMax + 1)
        self.helper(root.right, currMax + 1)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        currMax = 0
        if not root:
            return 0
        self.helper(root, currMax)

        return self.maxDepthNumber + 1

