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
    vector<int> answer;
    
    void TreeTraversal(TreeNode* root, bool isLeft)
    {
        if(root == NULL)
        {
            return;
        }

        if(root -> left == NULL && root -> right == NULL && isLeft == true)
        {
            answer.push_back(root -> val);
        }

        TreeTraversal(root -> left, true);
        TreeTraversal(root -> right, false);

    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(root == NULL)
        {
            return 0;
        }

        TreeTraversal(root, false);

        int count = 0;
        for(int i = 0; i < answer.size(); i++)
        {
            count += answer[i];
        }

        return count;
    }
};