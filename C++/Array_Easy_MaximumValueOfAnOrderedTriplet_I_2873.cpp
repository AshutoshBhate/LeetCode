class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios :: sync_with_stdio(false);
    
            int sizeofarray = nums.size();
            int last_index = nums.size() - 1;
    
            long long max_val = 0;
            int max_prefix = nums[0];
    
            vector<int> max_suffix(sizeofarray, 0);
            
            // Compute max_suffix[k] : max nums[k] for k > j
    
            max_suffix[last_index] = nums[last_index];
    
            for (int k = last_index; k > 0; k--)
            {
                max_suffix[k - 1] = max(max_suffix[k], nums[k - 1]);
            }
    
            // Iterate over j (middle element) and compute (nums[i] - nums[j]) * nums[k]
            for (int j = 1; j < last_index; j++)
            {
                max_val = max(max_val, (long long)(max_prefix - nums[j]) * max_suffix[j + 1]);
                max_prefix = max(max_prefix, nums[j]);
            }
    
            return max_val >= 0 ? max_val : 0;
        }
    };
    