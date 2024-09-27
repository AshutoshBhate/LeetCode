class Solution {
public:
    int search(vector<int>& nums, int target)
    {

        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

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
        return -1;
    }
};