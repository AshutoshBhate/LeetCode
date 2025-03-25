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
        TreeNode* deleteNode(TreeNode* root, int key)
        {
            // Check if the root is empty
            if (root == NULL)
            {
                // Return null if the root is empty
                return NULL;
            }
            
            // If the current root node has the key to be deleted
            if (root -> val == key)
            {
                // Delete the node using the helper function
                return helper(root);
            }
            
            // Use a pointer to traverse the tree
            TreeNode* curr = root;
            // While loop to traverse the tree
            while (curr != NULL)
            {
                if (key < curr -> val)
                {
                    // If the left child exists and its value matches the key
                    if (curr -> left != NULL && curr -> left -> val == key)
                    {
                        // Delete the node using the helper function
                        curr -> left = helper(curr -> left);
                        break;
                    }
                    else
                    {
                        // Move to the left subtree
                        curr = curr -> left;
                    }
                }
                else // key > curr -> val
                {
                    // If the right child exists and its value matches the key
                    if (curr -> right != NULL && curr -> right -> val == key)
                    {
                        // Delete the node using the helper function
                        curr -> right = helper(curr -> right);
                        break;
                    }
                    else
                    {
                        // Move to the right subtree
                        curr = curr -> right;
                    }
                }
            }
            
            // Return the modified tree
            return root;
        }
        
        // Helper function to delete the node
        TreeNode* helper(TreeNode* root)
        {
            // If the left child of the root is null, return the right child
            if (root -> left == NULL)
            {
                return root -> right;
            }
            else if (root -> right == NULL)
            {
                // If the right child is null, return the left child
                return root -> left;
            }
            
            // If both left and right children exist, store the right child
            TreeNode* rightChild = root -> right;
            
            // Find the last right child of the left subtree
            TreeNode* lastRight = findLastRight(root -> left);
            
            // Set the right child of the last right node to the stored right child
            lastRight -> right = rightChild;
            
            // Return the left child as the new subtree
            return root -> left;
        }
        
        // Helper function to find the last right node in a subtree
        TreeNode* findLastRight(TreeNode* root)
        {
            // Traverse to the rightmost node in the subtree
            if (root -> right == NULL)
            {
                // Return the rightmost node
                return root;
            }
            // Recursively find the last right node
            return findLastRight(root -> right);
        }
    };
    