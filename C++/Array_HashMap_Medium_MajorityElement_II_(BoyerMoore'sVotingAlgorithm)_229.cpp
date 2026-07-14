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

// My Solution 2 : 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> answer;
        sort(nums.begin(), nums.end());
        int threshold = nums.size()/3;
        int count = 0;
        int curr = nums[0];

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == curr)
            {
                count++;
            }
            else
            {
                if(count > threshold)
                {
                    answer.push_back(curr);
                }
                count = 0;
                curr = nums[i];
                count++;
            }
        }    

        if(count > threshold)
        {
            answer.push_back(curr);
        }

        return answer;
    }
};

//My Solution 3 :

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int element_1 = INT_MIN, element_2 = INT_MIN, count_1 = 0, count_2 = 0;

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

        return answer;
    }
};

