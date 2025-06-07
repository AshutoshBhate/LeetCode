class Solution {
public:
    string truncateSentence(string s, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(k == 0)
            {
                ans.pop_back();
                break;
            }
            if(s[i] != ' ')
            {
                ans += s[i];
            }
            if(s[i] == ' ')
            {
                ans += " ";
                k--;
            }
        }

        return ans;    
    }
};