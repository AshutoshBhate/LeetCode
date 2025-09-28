class Solution {
    public:
        int myAtoi(string s)
        {
            int MAX = INT_MAX, MIN = INT_MIN;
            int i = 0;
    
            if(s.size() == 0)
            {
                return 0;
            }
    
            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }
    
            if(i == s.size())
            {
                return 0;
            }
    
            s = s.substr(i);
    
            int sign = 1;
            long ans = 0;
    
            if(s[0] == '-')
            {
                sign = -1;
            }
    
            i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    
            while(i < s.size())
            {
                if(s[i] == ' ' || !isdigit(s[i]))
                {
                    break;
                }
    
                ans = ans * 10 + (s[i] - '0');
    
                if(sign == -1 && -1 * ans < MIN)
                {
                    return INT_MIN;
                }
                if(sign == 1 && ans > MAX)
                {
                    return INT_MAX;
                }
    
                i++;
            }
    
            return int (sign * ans);
        }
    };