class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> the_map;
        vector<int> myVector;

        for(int i = 0; i < nums.size(); i++)
        {
            the_map[nums[i]] = i;
        }
        for(int j = 0; j < nums.size(); j++)
        {
            int complement = target - nums[j];
            int key = complement;
            auto it = the_map.find(key);

            if(it != the_map.end() && (*it).second != j)
            {
                myVector.push_back(j);
                myVector.push_back((*it).second);
                break;
            }
           
        }

        return myVector;

    }
};