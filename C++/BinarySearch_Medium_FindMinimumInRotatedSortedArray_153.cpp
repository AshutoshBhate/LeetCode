//Identify the sorted half, take the smallest element from that half and store it. Eliminate the sorted half

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1, mid, sub_answer = 5000, answer = 5000;

        while(left <= right)
        {
            mid = (left + right)/2;
            if(nums[left] <= nums[mid])
            {
                sub_answer = nums[left];
                left = mid + 1;
            }
            else
            {
                sub_answer = nums[mid];
                right = mid - 1;
            }
            answer = min(sub_answer, answer);
        }   

        return answer; 
    }
};