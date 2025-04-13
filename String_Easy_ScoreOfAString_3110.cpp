class Solution {
    public:
        int scoreOfString(string s)
        {
            int k = s.size();
            int curr = 0, next = 0, addition = 0;
    
            for(int i = 0; i < k - 1; i++)
            {
                curr = s[i];
                next = s[i + 1];
    
                addition += (abs(curr - next));
            }
    
            return addition;
        }
    };