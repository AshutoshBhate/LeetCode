//My Method : Less Optimal

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int main_count = 0;
        int sub_count = 0;

        vector<int> vec(nums.size() + 1, -1);

        for(int i = 0; i < nums.size(); i++)
        {
            vec[nums[i]]++;
        }

        for(int i = 0; i < vec.size(); i++)
        {
            sub_count = 0;
            if(vec[i] == -1)
            {
                continue;
            }

            for(int j = vec[i]; j >= 0; j--)
            {
                sub_count += j;
            }
            main_count += sub_count;
        }

        return main_count;
    }
};

//ChatGPT Method : Optimal

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        vector<int> vec(101, 0);
        int count = 0;

        for (int num : nums)
        {
            count += vec[num]; 
            vec[num]++;
        }

        return count;
    }
};
