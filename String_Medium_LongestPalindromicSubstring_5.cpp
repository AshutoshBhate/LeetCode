class Solution {
public:

    void helperWhile(int left, int right, int& start, int& max_Length, string s)
    {
        while(left >= 0 && right < s.size())
        {
            if(s[left] == s[right])
            {
                if(right - left + 1 > max_Length)
                {
                    start = left;
                    max_Length = right - left + 1;
                }
                right++;
                left--;
            }
            else
            {
                break;
            }
        }
    }

    string longestPalindrome(string s)
    { 
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int max_Length = 0, start = 0, left, right;

        for(int i = 0; i < s.size(); i++)
        {
            //For odd length strings
            left = i, right = i;
            helperWhile(left, right, start, max_Length, s);

            //For even length strings
            left = i, right =  i + 1;
            helperWhile(left, right, start, max_Length, s);
            
        }

        return s.substr(start, max_Length);
    }
};