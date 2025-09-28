//Recursive Approach:

int findCeil(Node* root, int input)
{
    if(root == NULL)
    {
        return -1;
    }
    
    if(root -> data == input)
    {
        return root -> data;
    }
    
    if(root -> data < input)
    {
        return findCeil(root -> right, input);
    }
    else
    {
        int LeftCeil = findCeil(root -> left, input);
        return (LeftCeil >= input) ? LeftCeil : root -> data;
    }
}

//Normal Approach:

int findCeil(Node* root, int input)
{
    int ceil = -1; 
        
    while(root)
    {
        if(root-> data == input)
        {
            ceil = root-> data;
            return ceil;
        } 
            
        if(input > root->data)
        {
            root = root->right;
        }
        else
        { 
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}