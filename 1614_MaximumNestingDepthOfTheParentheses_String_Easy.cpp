class Solution {
public:
    int maxDepth(string s)
    {
        int max_count = 0, count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                count++;
            }
            if(s[i] == ')')
            {
                count--;
            }
            max_count = max(max_count, count);
        }

        return max_count;
    }
};