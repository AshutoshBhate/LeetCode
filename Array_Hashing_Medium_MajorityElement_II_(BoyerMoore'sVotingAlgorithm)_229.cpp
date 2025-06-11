//My Solution 1 : 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<int, int> myMap;
        map<int, int> :: iterator iter;
        vector<int> output;

        for(int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }

        int number = nums.size()/3;

        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            if((*iter).second > number)
            {
                output.push_back((*iter).first);
            }
        }

        return output;
    }
};

//My Solution 2 :

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int element_1 = 0, element_2 = 0, count_1 = 0, count_2 = 0;
        vector<int> answer;
        int boundary = nums.size()/3, master_count_1 = 0, master_count_2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count_1 == 0 && nums[i] != element_2)
            {
                count_1 = 1;
                element_1 = nums[i];
            }
            else if(count_2 == 0 && nums[i] != element_1)
            {
                count_2 = 1;
                element_2 = nums[i];
            }
            else if(nums[i] == element_1)
            {
                count_1++;
            }
            else if(nums[i] == element_2)
            {
                count_2++;
            }
            else
            {
                count_1--;
                count_2--;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(element_1 == nums[i])
            {
                master_count_1++;
            }
            if(element_2 == nums[i])
            {
                master_count_2++;
            }
        }
        if(master_count_1 > boundary)
        {
            answer.push_back(element_1);
        }
        if(master_count_2 > boundary)
        {
            answer.push_back(element_2);
        }
        if(element_1 == element_2)
        {
            answer.pop_back();
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};


//ChatGPT Solution : 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == candidate1)
            {
                count1++;
            }
            else if(nums[i] == candidate2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == candidate1)
            {
                count1++;
            }
            else if(nums[i] == candidate2)
            {
                count2++;
            }
        }

        vector<int> output;
        int number = nums.size() / 3;

        if(count1 > number)
        {
            output.push_back(candidate1);
        }
        if(count2 > number)
        {
            output.push_back(candidate2);
        }

        return output;
    }
};


