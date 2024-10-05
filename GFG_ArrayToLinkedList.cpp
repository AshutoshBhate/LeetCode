// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr)
    {
        Node* p = new Node(arr[0]);
        Node* current = p;
        
        if(arr.size() == 1)
        {
            return p;
        }
        
        Node* ptr;
        for(int i = 1; i < arr.size(); i++)
        {
            ptr = new Node(arr[i]);
            current -> next = ptr;
            current = ptr;
        }
        
        return p;  
    }
};