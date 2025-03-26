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

 //Striver Solution:

class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            if(root == NULL)
            {
                return new TreeNode(val);
            }
    
            TreeNode* curr = root;
    
            while(true)
            {
                if(curr -> val <= val)
                {
                    if(curr -> right != NULL)
                    {
                        curr = curr -> right;
                    }
                    else
                    {
                        curr -> right = new TreeNode(val);
                        break;
                    }
                }
                else
                {
                    if(curr -> left != NULL)
                    {
                        curr = curr -> left;
                    }
                    else
                    {
                        curr -> left = new TreeNode(val);
                        break;
                    }
                }
            }
    
            return root;
        }
};

//My Solution:

class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val)
        {
            TreeNode* ActualRoot = root;
            TreeNode* prev_node = NULL;
            TreeNode* node = new TreeNode(val);
    
    
            if(root == NULL)
            {
                TreeNode* newNode = new TreeNode(val);
                return newNode;
            }    
    
            while(root)
            {
                if(val > root -> val)
                {
                    prev_node = root;
                    root = root -> right;
                }
                else if(val < root -> val)
                {
                    prev_node = root;
                    root = root -> left;
                }
            }
    
            if(val > prev_node -> val)
            {
                prev_node -> right = node;
    
            }
            else
            {
                prev_node -> left = node;
            }
    
            return ActualRoot;
        }
};