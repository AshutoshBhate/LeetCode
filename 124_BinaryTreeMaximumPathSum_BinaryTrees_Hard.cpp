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

    int maxPathDown(TreeNode* root, int& maxi)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftSum = max(0, maxPathDown(root -> left, maxi));      //For leftSum and rightSum to no be negative
        int rightSum = max(0, maxPathDown(root -> right, maxi));

        maxi = max(maxi, root -> val + leftSum + rightSum);
        return root -> val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root)
    {
        int max = INT_MIN;
        int dummy = maxPathDown(root, max);

        return max;
    }
};