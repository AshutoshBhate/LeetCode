class Solution {
public:
    bool isAnagram(string s, string t)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};