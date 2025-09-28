class Solution {
public:
    int minAddToMakeValid(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int open = 0, close = 0, count = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')' && (open == 0 || open == close))
            {
                open = 0;
                close = 0;
                count++;
                continue;
            }
            if(s[i] == '(')
            {
                open++;
            }
            if(s[i] == ')')
            {
                close++;
            }
        }

        count += abs(open - close);

        return count;
    }
};