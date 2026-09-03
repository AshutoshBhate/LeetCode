/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) 
    {
        vector<int> answer;
        if(root == NULL)
        {
            return answer;
        }
        
        int curr_num = 0;
        
        map<int, int> myMap;
        queue<pair<Node*, int>> myQueue;
        
        myQueue.push({root, curr_num});
        
        while(!myQueue.empty())
        {
            myMap[myQueue.front().second] = myQueue.front().first -> data;
            
            if(myQueue.front().first -> left)
            {
                myQueue.push({myQueue.front().first -> left, myQueue.front().second - 1});
            }
            if(myQueue.front().first -> right)
            {
                myQueue.push({myQueue.front().first -> right, myQueue.front().second + 1});
            }
            
            myQueue.pop();
        }
        
        for(auto iter : myMap)
        {
            answer.push_back(iter.second);
        }
        
        return answer;
    }
};