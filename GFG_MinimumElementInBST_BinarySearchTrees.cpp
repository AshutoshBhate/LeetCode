// User function Template for C++

// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    vector<int> ans;
    
    void inOrder(Node* root)
    {
        if(root != NULL)
        {
            inOrder(root -> left);
            ans.push_back(root -> data);
            inOrder(root -> right);
        }
    }
  
    int minValue(Node* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        inOrder(root);
        
        return ans[0];
    }
};