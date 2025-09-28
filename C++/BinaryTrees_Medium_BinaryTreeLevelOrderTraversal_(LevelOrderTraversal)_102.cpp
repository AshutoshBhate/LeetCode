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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans; 
        }

        queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty())
        {
            int size = q.size();    //Size of the current level
            vector<int> level; 

            for (int i = 0; i < size; i++)
            {
                // Get the front node in the queue
                TreeNode* node = q.front();

                // Remove the front node from the queue
                q.pop(); 

                // Store the node value in the current level vector
                level.push_back(node->val); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            // Store the current level in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order traversal of the tree
        return ans; 
    }
};