// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr)
    {
        Node* head = new Node(arr[0]);
        
        Node* p = head;
        if(arr.size() == 1)
        {
            return head;
        }
        
        for(int i = 1; i < arr.size(); i++)
        {
            Node* ptr = new Node(arr[i]);
            p -> next = ptr;
            ptr -> prev = p;
            p = p -> next;
        }
        
        return head;
    }
};