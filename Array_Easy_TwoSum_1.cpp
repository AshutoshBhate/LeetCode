//Brute Force :

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> solution_array(0);
        bool flag = false;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target && i != j)
                {
                    solution_array.push_back(i);
                    solution_array.push_back(j);
                    flag = true;
                }
                if(flag == true)
                {
                    break;
                }
            }

            if(flag == true)
            {
                break;
            }
        }

        return solution_array;
    }
};

//Two Pass Hash Table : Optimal

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> the_map;
        vector<int> myVector;

        for(int i = 0; i < nums.size(); i++)
        {
            the_map[nums[i]] = i;
        }

        for(int j = 0; j < nums.size(); j++)
        {
            int complement = target - nums[j];
            int key = complement;
            auto it = the_map.find(key);

            if(it != the_map.end() && (*it).second != j)
            {
                myVector.push_back(j);
                myVector.push_back((*it).second);
                break;
            }
        }

        return myVector;
    }
};