class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        unordered_map<int, int> myMap;
        vector<int> answer(2, 0);

        for(int i = 1; i <= nums.size(); i++)
        {
            myMap[i] = 0;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }    

        for(auto it : myMap)
        {
            if(it.second == 2)
            {
                answer[0] = it.first;
            }
            if(it.second == 0)
            {
                answer[1] = it.first;
            }
        }

        return answer;
    }
};

// Optimal Solution implementation is in python language