class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i, first_switch, second_switch, first_number, second_number;
        map<int, int> mymap;

        for(i = nums.size() - 1; i > 0; i--)
        {
           if(nums[i - 1] < nums[i])
           {
                for(int j  = i - 1; j < nums.size(); j++)
                {
                    mymap.emplace(nums[j], j);
                }
                first_number = nums[i - 1];
                auto first_it = mymap.find(first_number);
                first_switch = first_it->second;

                
                first_it++;
                second_number = first_it->first;
                second_switch = first_it->second;
                swap(nums[first_switch], nums[second_switch]);
                break;
           } 
        }
        sort(nums.begin() + i, nums.end());
    }
};