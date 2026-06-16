//Gemini Solution : Recursion

class Solution {
public:
    bool validate(TreeNode* node, long long min_bound, long long max_bound) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min_bound || node->val >= max_bound) {
            return false;
        }

        return validate(node->left, min_bound, node->val) && 
               validate(node->right, node->val, max_bound);
    }

    bool isValidBST(TreeNode* root) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);
        
        return validate(root, -2147483648LL - 1, 2147483647LL + 1); 
    }
};

//My Solution : Recursion 

class Solution {
public:

    bool helper(TreeNode* root, long long lower_bound, long long upper_bound)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root -> val <= lower_bound || root -> val >= upper_bound)
        {
            return false;
        }

        return helper(root -> left, lower_bound, root -> val) && helper(root -> right, root -> val, upper_bound);
    }

    bool isValidBST(TreeNode* root) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

//My Solution : Inorder + Strictly increasing check

class Solution {
public:

    void inOrder(TreeNode* root, vector<int>& inOrder_vec)
    {
        if(root == NULL)
        {
            return;
        }

        inOrder(root -> left, inOrder_vec);
        inOrder_vec.push_back(root -> val);
        inOrder(root -> right, inOrder_vec);
    }

    bool isValidBST(TreeNode* root) 
    {

        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        vector<int> inOrder_vec;

        inOrder(root, inOrder_vec);

        long long initial = LLONG_MIN;

        for(int i = 0; i < inOrder_vec.size(); i++)
        {
            if(inOrder_vec[i] <= initial)
            {
                return false;
            }
            initial = inOrder_vec[i];
        }

        return true;   
    }
};



