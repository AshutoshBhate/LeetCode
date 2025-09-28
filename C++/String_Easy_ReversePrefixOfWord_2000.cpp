class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<char> vec;
        string ans;

        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                vec.push_back(word[i]);
                for(int j = vec.size() - 1; j >= 0; j--)
                {
                    ans.push_back(vec[j]);
                }
                for(int k = i + 1; k < word.size(); k++)
                {
                    ans.push_back(word[k]);
                }
                break;
            }
            else if(word[i] != ch && i != word.size() - 1)
            {
                vec.push_back(word[i]);
            }
            else
            {
                return word;
            }
        }

        return ans;    
    }
};