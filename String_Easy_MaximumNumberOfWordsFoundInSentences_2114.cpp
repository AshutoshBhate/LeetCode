class Solution {
public:
    int mostWordsFound(vector<string>& sentences)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int max_count = 0;

        for(int i = 0; i < sentences.size(); i++)
        {
            int count = 1;

            for(int j = 0; j < sentences[i].size(); j++)
            {
                if(sentences[i][j] == ' ')
                {
                    count += 1;
                }
            }
            max_count = max(max_count, count);
        }

        return max_count;
    }
};