class Solution {
public:
    string frequencySort(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        map<char, int> myMap;
        string answer;

        for(int i = 0; i < s.size(); i++)
        {
            myMap[s[i]]++;
        }

        vector<pair<char, int>> myVec(myMap.begin(), myMap.end());

        sort(myVec.begin(), myVec.end(), [](pair<char, int> a, pair<char, int> b)
        {
            return a.second > b.second;
        });

        for(int j = 0; j < myVec.size(); j++)
        {
            for(int k = 0; k < myVec[j].second; k++)
            {
                answer.push_back(myVec[j].first);
            }
        }

        return answer;
    }
};