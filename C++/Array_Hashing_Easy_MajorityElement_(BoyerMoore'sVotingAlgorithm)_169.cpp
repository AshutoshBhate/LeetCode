//My Solution : 

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        map<long, long> majority_map;
        long limit_no = nums.size()/2;
        map<long, long> :: iterator iter;

        for(long i = 0; i < nums.size(); i++)
        {
            majority_map[nums[i]]++;
        }

        for(iter = majority_map.begin(); iter != majority_map.end(); iter++)
        {
            if((*iter).second > limit_no)
            {
                return (*iter).first;
            }
        }

        return 0;
    }
};

//Striver Solution : Boyer-Moore Majority Vote Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0, element = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                count = 1;
                element = nums[i];
            }
            else if(nums[i] == element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == element)
            {
                count++;
            }
        }
        if(count > (nums.size() / 2))
        {
            return element;
        }
        else
        {
            return -1;
        }
    }
};