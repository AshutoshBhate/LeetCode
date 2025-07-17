//Two Loop Solution : 

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int max_num = INT_MIN, prefix = 1, suffix = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(prefix == 0)
            {
                prefix = 1;
            }
            prefix *= nums[i];
            max_num = max(prefix, max_num); 
        }

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(suffix == 0)
            {
                suffix = 1;
            }
            suffix *= nums[i];
            max_num = max(suffix, max_num);
        }    

        return max_num;
    }
};

//Single Loop :

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int max_num = INT_MIN, prefix = 1, suffix = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(prefix == 0)
            {
                prefix = 1;
            }
            if(suffix == 0)
            {
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[nums.size() - 1 - i];
            max_num = max(max_num, max(prefix, suffix)); 
        }  

        return max_num;
    }
};