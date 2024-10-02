class Solution {
public:
    int lengthOfLastWord(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        auto iter = s.find_last_not_of(' ');
        if(iter != string::npos)
        {
            s.erase((s.begin() + (iter + 1)), s.end());
        }

        auto it = s.find_last_of(' ');
        string last_string = s.substr(it + 1);

        return last_string.size();
    }
};