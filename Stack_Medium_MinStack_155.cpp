//Naive O(2N) Solution:

class MinStack {
    stack<pair<int, int>> myStack;
    public:
    
    void push(int val)
    {
        if(myStack.empty())
        {
            myStack.push({val, val});
        }
        else
        {
            myStack.push({val, min(val, myStack.top().second)});
        }
    }
    
    void pop()
    {
        myStack.pop();
    }
    
    int top() {
        return myStack.top().first;
    }
    
    int getMin() {
        return myStack.top().second;
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */