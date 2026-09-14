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
    int amountOfTime(TreeNode* root, int start) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 0;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> myQueue;
        TreeNode* start_node;

        myQueue.push(root);
        parentMap[root] = NULL;

        while(!myQueue.empty())
        {
            if(myQueue.front() -> val == start)
            {
                start_node = myQueue.front();
            }

            if(myQueue.front() -> left)
            {
                myQueue.push(myQueue.front() -> left);
                parentMap[myQueue.front() -> left] = myQueue.front();
            }
            if(myQueue.front() -> right)
            {
                myQueue.push(myQueue.front() -> right);
                parentMap[myQueue.front() -> right] = myQueue.front();
            }

            myQueue.pop();
        }

        //Now the real BFS starts : 

        unordered_map<int, int> visited_map;
        myQueue.push(start_node);
        visited_map[start_node -> val] = 1;

        while(!myQueue.empty())
        {
            int currSize = myQueue.size();
            for(int i = 0; i < currSize; i++)
            {
                TreeNode* currNode = myQueue.front();

                if(currNode -> left != NULL && visited_map[currNode -> left -> val] != 1)
                {
                    myQueue.push(currNode -> left);
                    visited_map[currNode -> left -> val] = 1;
                }
                if(currNode -> right != NULL && visited_map[currNode -> right -> val] != 1)
                {
                    myQueue.push(currNode -> right);
                    visited_map[currNode -> right -> val] = 1;
                }
                if(parentMap[currNode] != NULL && visited_map[parentMap[currNode] -> val] != 1)
                {
                    myQueue.push(parentMap[currNode]);
                    visited_map[parentMap[currNode] -> val] = 1;
                }
                
                myQueue.pop();
            }

            count++;
        }

        return count - 1;
    }
};