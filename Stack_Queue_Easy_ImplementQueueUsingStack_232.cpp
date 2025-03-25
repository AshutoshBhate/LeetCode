class MyQueue
{
    stack<int> s;
    stack<int> s_new;

    public:
        void push(int x)
        { 
            s.push(x);
        }

        int pop()
        {
            if(s_new.empty())
            {
                // Transfer elements from s to s_new if s_new is empty
                while (!s.empty())
                {
                    s_new.push(s.top());
                    s.pop();
                }
            }
            if (!s_new.empty())
            {
                int val = s_new.top(); // Get the top element (front of the queue)
                s_new.pop();
                return val;
            }
            return 0;
        }

        int peek()
        {
            if (s_new.empty())
            {
                while (!s.empty())
                {
                    s_new.push(s.top());
                    s.pop();
                }
            }
            return s_new.top();
        }

        bool empty()
        {
            if (s_new.empty())
            {
                while (!s.empty())
                {
                    s_new.push(s.top());
                    s.pop();
                }

                if(s_new.empty())
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
            return 0;
        }
};

/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */