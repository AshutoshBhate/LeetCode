class Solution {
public:
    int balancedStringSplit(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int R_count = 0, L_count = 0, split_count = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'R')
            {
                R_count++;
            }
            else
            {
                L_count++;
            }

            if(R_count == L_count)
            {
                split_count++;
                R_count = 0;
                L_count = 0;
            }
        }    

        return split_count;
    }
};