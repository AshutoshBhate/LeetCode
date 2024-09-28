class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        unordered_map<int, int> myMap;
        int current_number, len = 0, MinLength = k + 1;

        for(int i = 0; i < nums.size(); i++)
        {
            current_number = nums[i];
            if(myMap.find(current_number) == myMap.end())
            {
                myMap[current_number] = i;
            }
            else
            {
                len = i - myMap[current_number];
                myMap[current_number] = i;
                MinLength = min(len, MinLength);
            }
        }
        if(MinLength <= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};