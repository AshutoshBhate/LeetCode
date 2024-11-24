class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int i = 0, j = 0, length = 0, max_length = 0, zeros = 0;

        while(j < nums.size())
        {
            if(nums[j] == 0 && zeros <= k)
            {
                zeros += 1;
            }
            if(nums[j] == 0 && zeros > k)
            {
                while(!(zeros <= k))
                {
                    if(nums[i] == 0)
                    {
                        i += 1;
                        zeros -= 1;
                    }
                    else
                    {
                        i += 1;
                    }

                }
            }
            length = j - i + 1;
            max_length = max(max_length, length);

            j++;
        }

        return max_length;
    }
};