class Solution {
public:
    bool isValid(string s)
    {
        stack<char> myStack;
        char x;
        bool flag = true;

        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                myStack.push(s[i]);
            }
            else
            {
                if(myStack.empty())
                {
                    return false;
                }
                else
                {
                    x = myStack.top();
                    myStack.pop();

                    if(s[i] == ')' && x == '(')
                    {
                        continue;
                    }
                    else if(s[i] == ']' && x == '[')
                    {
                        continue;
                    }
                    else if(s[i] == '}' && x == '{')
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }  
        if(!myStack.empty())
        {
            return false;
        }

        return flag;  
    }
};