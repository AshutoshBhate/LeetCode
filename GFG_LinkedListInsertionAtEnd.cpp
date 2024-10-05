/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x)
    {
        Node* p = head;
        Node* ptr = new Node(x);
        
        if(p == NULL)
        {
            return ptr;
        }
        
        while(p -> next != NULL)
        {
            p = p -> next;
        }
        
        p -> next = ptr;    
        ptr -> next = NULL;
        
        return head;
    }
};
