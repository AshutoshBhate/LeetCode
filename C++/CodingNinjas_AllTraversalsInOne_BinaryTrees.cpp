/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<vector<int>> answer;
vector<int>preOrder_vec;
vector<int>inOrder_vec;
vector<int>postOrder_vec;

vector<int> preOrder(TreeNode* root)
{
    if(root != NULL)
    {
        preOrder_vec.push_back(root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }

    return preOrder_vec;
}

vector<int> inOrder(TreeNode* root)
{
    if(root != NULL)
    {
        inOrder(root -> left);
        inOrder_vec.push_back(root -> data);
        inOrder(root -> right);
    }

    return inOrder_vec;
}

vector<int> postOrder(TreeNode* root)
{
    if(root != NULL)
    {
        postOrder(root -> left);
        postOrder(root -> right);
        postOrder_vec.push_back(root -> data);
    }

    return postOrder_vec;
}



vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    answer.push_back(inOrder(root));
    answer.push_back(preOrder(root));
    answer.push_back(postOrder(root));
    
    return answer;
}