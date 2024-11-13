class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<int, int> myMap;
        int j = 0;
        vector<int> answer;

        sort(items.begin(), items.end());
        int current_max = items[0][1];

        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][j + 1] >= myMap[items[i][j]])
            {
                myMap[items[i][j]] = items[i][j + 1];
                if(current_max > items[i][j + 1])
                {
                    myMap[items[i][j]] = current_max;
                }
                else
                {
                    current_max = items[i][j + 1];
                }
            }
            else
            {
                continue;
            }
        }

        for(int k = 0; k < queries.size(); k++)
        {
            auto it = myMap.upper_bound(queries[k]);

            if(it == myMap.begin())
            {
                answer.push_back(0);
            }
            else
            {
                --it;
                answer.push_back((*it).second);
            }
        }

        return answer;
    }
};