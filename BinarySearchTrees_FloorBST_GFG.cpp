//Recursive Approach:

int floor(Node* root, int x) 
{
    if(root == NULL)
    {
        return -1;
    }
    if(root -> data == x)
    {
        return root -> data;
    }
    if(root -> data > x)
    {
        return floor(root -> left, x);
    }
    else
    {
        int RightFloor = floor(root -> right, x);
        if(RightFloor != -1)
        {
            return RightFloor;
        }
        else
        {
            return root -> data;
        }
    }
}

//Normal Approach:

class Solution{

    public:
        int floor(Node* root, int x)
        {
            int floor_no = -1;
            
            while(root)
            {
                if(root -> data == x)
                {
                    return root -> data;
                }
                if(root -> data > x)
                {
                    root = root -> left;
                }
                else
                {
                    floor_no = root -> data;
                    root = root -> right;
                }
            }
            
            return floor_no;
        }
    };

