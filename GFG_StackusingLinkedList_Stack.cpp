class MyStack {
  private:
    StackNode *top;

  public:
  
    MyStack()
    { 
        top = NULL;
    }
    
    void push(int x)
    {
        StackNode* ptr = new StackNode(x);
        ptr -> next = top;
        top = ptr;
    }

    int pop()
    {
        if(top == NULL)
        {
            return -1;
        }
        else
        {
            int poppedData = top -> data;
            StackNode* temp = top;
            top = top -> next;
            delete temp;
            return poppedData;
        }
    }
};