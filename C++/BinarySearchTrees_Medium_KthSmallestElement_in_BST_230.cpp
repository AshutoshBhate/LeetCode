//My Solution:

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
        vector<int> inOrder_array;
    
        void inOrderTraversal(TreeNode* root)
        {
            if(root == NULL)
            {
                return;
            }
    
            inOrderTraversal(root -> left);
            inOrder_array.push_back(root -> val);
            inOrderTraversal(root -> right);
        }
    
        int kthSmallest(TreeNode* root, int k)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(false);
    
            inOrderTraversal(root);
    
            return inOrder_array[k - 1];
        }
    };

//Optimal Approach:

class Solution {
    public:
        void inOrderTraversal(TreeNode* root, int k, int& count, int& result)
        {
            if (root == NULL)
            {
                return;
            }
    
            inOrderTraversal(root->left, k, count, result);
            
            count++;
            if (count == k)
            {
                result = root->val;
                return; // Early exit
            }
    
            inOrderTraversal(root->right, k, count, result);
        }

        int kthSmallest(TreeNode* root, int k)
        {
            int count = 0;
            int result = -1;

            inOrderTraversal(root, k, count, result);
            
            return result;
        }
};