class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        unordered_map<int, int> myMap;
        unordered_map<int, int> :: iterator iter;
        vector<int> answer;

        for(int i = 1; i <= nums.size(); i++)
        {
            myMap[i] = 0;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }

        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            if((*iter).second == 0)
            {
                answer.push_back((*iter).first);
            }
        }

        return answer;
    }
};