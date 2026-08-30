# Gemini's Approach 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxGain(self, root):
        if root == None:
            return 0

        leftGain = max(self.maxGain(root.left), 0)
        rightGain = max(self.maxGain(root.right), 0)

        self.max_sum = max(self.max_sum, root.val + leftGain + rightGain)

        return root.val + max(leftGain, rightGain)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float(-inf)
        self.maxGain(root)

        return self.max_sum
