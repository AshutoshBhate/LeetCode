class Solution {
    public:
        bool checkValidString(string s)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            int minOpen = 0, maxOpen = 0;
    
            for(int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                {
                    minOpen++;
                    maxOpen++;
                } 
                else if (s[i] == ')')
                {
                    minOpen--;
                    maxOpen--;
                }
                else if (s[i] == '*')
                {
                    // '*' can be treated as:
                    // - a ')': decreasing minOpen,
                    // - an empty string: leaving the count unchanged,
                    // - or a '(': increasing maxOpen.
                    minOpen--; // assume it's a ')'
                    maxOpen++; // assume it's a '('
                }
    
                if(minOpen < 0)
                {
                    minOpen = 0;
                }
                
                // If maxOpen becomes negative, then even considering '*' as '(' cannot save us.
                if (maxOpen < 0)
                {
                    return false;
                }
            }
            
            // For a valid string, the minimum possible open parentheses should be 0.
            return minOpen == 0;
        }
    };
    