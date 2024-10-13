/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {

        map<Node*, int> myMap;
        map<Node*, int> :: iterator it;
        Node* ptr = head;
        int count = 1;

        while(ptr != NULL)
        {
            it = myMap.find(ptr);
            if(it != myMap.end())
            {
                break;
            }
            else
            {
                myMap[ptr] = ptr -> data;
                ptr = ptr -> next;
            }
        }
        
        if(ptr == NULL)
        {
            return 0;
        }
        
        Node* p = ptr;
        
        while(ptr -> next != p)
        {
            count++;
            ptr = ptr -> next;
        }
        
        return count;
    }
};