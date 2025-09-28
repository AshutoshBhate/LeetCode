class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        multimap<int, int> myMap;
        vector<int> answer(arr.size(), 0);
        multimap<int, int> :: iterator iter;

        for(int i = 0; i < arr.size(); i++)
        {
            myMap.emplace(arr[i], i);
        }

        iter = myMap.begin();
        int pastnumber = (*iter).first + 1;
        int statsize = 0;

        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            if(pastnumber == (*iter).first)
            {
                answer[(*iter).second] = statsize;
            }
            else
            {  
                statsize++;
                answer[(*iter).second] = statsize;
            }
            pastnumber = (*iter).first;
        }

        return answer;
    }
};