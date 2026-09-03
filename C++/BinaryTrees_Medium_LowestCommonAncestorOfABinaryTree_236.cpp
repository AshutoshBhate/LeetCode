// Intuition:
// To find the Lowest Common Ancestor (LCA) of nodes p and q in a Binary Tree:
// We perform a post-order / DFS traversal starting from the root.
// 1. Base Case: If the current node is NULL, or if current node is equal to p or q, return root.
// 2. Recurse down the left and right subtrees.
// 3. Evaluation:
//    - If both left and right return non-NULL pointers, it means p and q are found in different
//      subtrees of the current node. Therefore, the current node is their lowest common ancestor.
//    - If only one subtree returns a non-NULL pointer, we bubble up that non-NULL result (since both
//      nodes or their LCA reside in that subtree).
//    - If both subtrees return NULL, return NULL.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL)
        {
            return root;
        }
        else if(left == NULL)
        {
            return right;
        }
        else
        {
            return left;
        }
    }
};
