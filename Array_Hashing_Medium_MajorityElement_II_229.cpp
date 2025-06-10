//My Solution : 

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

//Striver Solution : Boyer-Moore Majority Vote Algorithm




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


