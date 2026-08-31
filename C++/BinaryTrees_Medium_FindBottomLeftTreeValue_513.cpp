// My Approach: (Pre-order DFS Traversal with Level Tracking)

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
private:
    int curr_level = 0, level = 0, leftMost;
public:

    void helper(TreeNode* root, int curr_level)
    {
        if(root == NULL)
        {
            return;
        }

        if(curr_level > level && (root -> left || root -> right))
        {
            if(root -> left)
            {
                leftMost = root -> left -> val;
            }
            else
            {
                leftMost = root -> right -> val;
            }

            level++;
        }

        helper(root -> left, curr_level + 1);
        helper(root -> right, curr_level + 1);
    }

    int findBottomLeftValue(TreeNode* root) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        leftMost = root -> val;
        helper(root, curr_level + 1);

        return leftMost;
    }
};


// Gemini's Approach:

#include <queue>

// Intuition for BFS (Right-to-Left Level-Order Traversal):
// Process nodes level by level. By enqueueing the right child before the left child,
// each level is visited from right to left. The very last node dequeued is guaranteed
// to be the bottom-leftmost node of the entire tree.

class SolutionBFS {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = root;

        while (!q.empty()) 
        {
            curr = q.front();
            q.pop();

            if (curr->right) 
            {
                q.push(curr->right);
            }
            if (curr->left) 
            {
                q.push(curr->left);
            }
        }

        return curr->val;
    }
};


// Intuition for DFS (Pre-order Traversal tracking Max Depth):
// Traverse the tree left child first, then right child. Whenever we visit a depth greater
// than the maximum depth recorded so far, the current node is the leftmost node at that new depth.
// Update the recorded value and max depth.

class SolutionDFS {
private:
    int maxDepth = -1;
    int leftmostVal = 0;

    void dfs(TreeNode* node, int depth) 
    {
        if (!node) return;

        if (depth > maxDepth) 
        {
            maxDepth = depth;
            leftmostVal = node->val;
        }

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

public:
    int findBottomLeftValue(TreeNode* root) 
    {
        dfs(root, 0);
        return leftmostVal;
    }
};