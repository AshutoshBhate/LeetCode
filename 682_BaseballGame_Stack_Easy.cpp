class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> myStack;
        int removedElement, sum, answer = 0;

        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "+")
            {
                removedElement = myStack.top();
                myStack.pop();
                sum = removedElement + myStack.top();
                myStack.push(removedElement);
                myStack.push(sum);
            }
            else if(operations[i] == "C")
            {
                myStack.pop();
            }
            else if(operations[i] == "D")
            {
                myStack.push(myStack.top() * 2);
            }
            else
            {
                myStack.push(stoi(operations[i]));
            }
        }

        while(!myStack.empty())
        {
            answer = answer + myStack.top();
            myStack.pop();
        }

        return answer;
    }
};