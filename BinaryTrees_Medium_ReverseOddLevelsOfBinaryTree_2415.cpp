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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(root == NULL)
        {
            return NULL;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int level_size = q.size();
            vector<TreeNode*> level_nodes;

            for(int i = 0; i < level_size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level_nodes.push_back(node);

                if(node -> left != NULL)
                {
                    q.push(node -> left);
                }
                if(node -> right != NULL)
                {
                    q.push(node -> right);
                }
            }

            if(level % 2 != 0)
            {
                int i = 0, j = level_nodes.size() - 1;

                while(i < j)
                {
                    int dummy = level_nodes[i] -> val;
                    level_nodes[i] -> val = level_nodes[j] -> val;
                    level_nodes[j] -> val = dummy;
                    i++;
                    j--;
                }
            }

            level += 1;
            level_nodes.clear();
        }

        return root;
    }
};