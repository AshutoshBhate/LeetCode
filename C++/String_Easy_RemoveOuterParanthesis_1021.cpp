class Solution {
public:
    string removeOuterParentheses(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int forward_counter = 0, backward_counter = 0;
        string answer;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                if(s[i] == '(' && forward_counter > 0)
                {
                    answer += '(';
                    forward_counter++;
                }
                else
                {
                    forward_counter++;
                }
            }
            else
            {
                if(forward_counter > 1)
                {
                    answer += ')';
                    forward_counter--;
                }
                else
                {
                    forward_counter--;
                }
            } 
        }

        return answer;
    }
};