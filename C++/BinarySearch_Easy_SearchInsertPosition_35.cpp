class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, right = nums.size() - 1;
        int middle;

        while(left <= right)
        {
            middle = (left + right)/2;
            if(nums[middle] == target)
            {
                return middle;
            }
            if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return left;        //Left is already pointing at the position where target must be inserted
    }
};