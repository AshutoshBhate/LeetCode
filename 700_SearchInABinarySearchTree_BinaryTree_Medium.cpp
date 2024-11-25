//Inorder Traversal Approach

/*
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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            return NULL;
        }    
        if(root -> val == val)
        {
            return root;
        }

        TreeNode* ptr = searchBST(root -> left, val);
        if(ptr != NULL)
        {
            return ptr;
        }
        else
        {
            return searchBST(root -> right, val);
        }
    }
};

//Optimal Approach:

/*
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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        while(root != NULL && root -> val != val)
        {
            if(root -> val > val)
            {
                root = root -> left;
            }
            else
            {
                root = root -> right;
            }
        }
        return root;
    }
};