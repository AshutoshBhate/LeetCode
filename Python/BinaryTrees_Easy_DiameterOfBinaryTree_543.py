# Gemini's Approach : 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def height(self, root):
        if root == None:
            return 0

        leftHeight = self.height(root.left)
        rightHeight = self.height(root.right)

        self.max_diameter = max(self.max_diameter, leftHeight + rightHeight)

        return 1 + max(leftHeight, rightHeight)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0
        self.height(root)

        return self.max_diameter
