class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);
        
        vector<int> answer;
        vector<int> :: iterator lower, upper;

        lower = lower_bound(nums.begin(), nums.end(), target);      //LowerBound Implememntation
        upper = upper_bound(nums.begin(), nums.end(), target);      //UpperBound Implementation

        if (lower == nums.end() || *lower != target)
        {
            return {-1, -1};
        }

        answer.push_back(lower - nums.begin());
        answer.push_back(upper - nums.begin() - 1);

        return answer;
        
    }
};