class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<int, int> myMap;
        // map<int, int> :: iterator iter;

        for(int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }

        // for(iter = myMap.begin(); iter != myMap.end(); iter++)
        // {
        //     if((*iter).second == 1)
        //     {
        //         return iter -> first;
        //     }
        // }

        for(auto itr : myMap)
        {
            if(itr.second == 1)
            {
                return itr.first;
            }
        }

        return 0;
    }
};