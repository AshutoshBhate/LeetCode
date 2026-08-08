// No return value, directly change the tree in memory : 

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return root;
        }

        invertTree(root -> left);

        TreeNode* temp = root -> right;
        root -> right = root -> left;
        root -> left = temp;

        invertTree(root -> left);  

        return root;  
    }
};

// With the return values to functions if it triggers OCD for the first code, as there
// are no return values assigned for TreeNode* type function

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return root;
        }

        TreeNode* leftInvertedBranch = invertTree(root -> left);
        TreeNode* rightInvertedBranch = invertTree(root -> right); 

        root -> left = rightInvertedBranch;
        root -> right = leftInvertedBranch;

        return root;  
    }
};