class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string string_1 = "";
        string string_2 = "";

        for(int i = 0; i < word1.size(); i++)
        {
            string_1 += word1[i];
        }
        for(int i = 0; i < word2.size(); i++)
        {
            string_2 += word2[i];
        }

        if(string_1.size() != string_2.size())
        {
            return false;
        }

        for(int i = 0; i < string_1.size(); i++)
        {
            if(string_1[i] != string_2[i])
            {
                return false;
            }
        }

        return true;
    }
};