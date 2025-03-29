/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
public:
    void create_tree(node* root0, vector<int>& vec) {
        // Create nodes for the tree
        node* node1 = newNode(vec[1]);
        node* node2 = newNode(vec[2]);
        node* node3 = newNode(vec[3]);
        node* node4 = newNode(vec[4]);
        node* node5 = newNode(vec[5]);
        node* node6 = newNode(vec[6]);

        // Construct the tree structure
        root0->left = node1;
        root0->right = node2;

        node1->left = node3;
        node1->right = node4;

        node2->left = node5;
        node2->right = node6;
    }
};