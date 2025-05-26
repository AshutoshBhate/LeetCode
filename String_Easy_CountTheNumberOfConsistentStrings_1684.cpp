class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        cin.tie(nullptr);
        cin.tie(nullptr);
        ios::sync_with_stdio(false);

        set<char> sq;

        for(int i = 0; i < allowed.size(); i++)
        {
            sq.insert(allowed[i]);
        }

        int count = 0;

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(sq.find(words[i][j]) == sq.end())
                {
                    break;
                }
                if(j == words[i].size() - 1 && sq.find(words[i][j]) != sq.end())
                {
                    count++;
                }
            }
        }

        return count;
    }
};