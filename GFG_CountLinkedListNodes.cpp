/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head)
    {
        if(head == NULL)
        {
            return 0;
        }
        
        int count = 1;
        
        Node* ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
            count++;
        }
        
        return count;
    }
};