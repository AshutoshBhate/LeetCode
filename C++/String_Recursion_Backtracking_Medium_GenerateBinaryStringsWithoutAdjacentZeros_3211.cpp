class Solution {
public:

    void helper(int n, string current_string, vector<string>& result)
    {
        if(current_string.size() == n)
        {
            result.push_back(current_string);
            return;
        }

        helper(n, current_string + '1', result);

        if(current_string.empty() || current_string.back() != '0')
        {
            helper(n, current_string + '0', result);
        }
    }

    vector<string> validStrings(int n)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<string> result;
        string current_string;

        helper(n, current_string, result);

        return result;    
    }
};