/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // Step 1: If both nodes are null, the trees are identical at this point.
        // if (p == nullptr && q == nullptr)
        // {
        //     return true;
        // }

        // // Step 2: If one node is null and the other is not, the trees are not the same.
        // if (p == nullptr || q == nullptr)
        // {
        //     return false;
        // }

        if(p == NULL || q == NULL)
        {
            return (p == q);
        }

        // Step 3: Check if the current nodes have the same value.
        if (p->val != q->val)
        {
            return false;
        }

        // Step 4: Recursively check the left and right subtrees.
        bool leftSame = isSameTree(p->left, q->left);
        bool rightSame = isSameTree(p->right, q->right);

        // Step 5: Return true only if both left and right subtrees are identical.
        //return leftSame && rightSame;

        if(leftSame == rightSame && leftSame == true && rightSame == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};