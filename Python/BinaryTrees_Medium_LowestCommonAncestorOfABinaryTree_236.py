# Intuition:
# To find the Lowest Common Ancestor (LCA) of nodes p and q in a Binary Tree:
# We perform a recursive DFS traversal starting from the root.
# 1. Base Case: If the current node is None, or if root is p or q, return root.
# 2. Recurse down the left and right subtrees.
# 3. Evaluation:
#    - If both left and right return a non-None node, p and q are in separate subtrees of the current node,
#      making the current root their lowest common ancestor.
#    - If only one side returns a non-None node, propagate that node up.
#    - If both return None, return None.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None or root == p or root == q:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root

        return left if left else right
