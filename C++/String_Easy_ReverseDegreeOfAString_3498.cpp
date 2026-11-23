class Solution {
public:
    int reverseDegree(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 0;

        for(int i = 0; i < s.size(); i++)
        {
            int reverse_index = 'z' - s[i] + 1;
            count += reverse_index * (i + 1);
        }

        return count;     
    }
};