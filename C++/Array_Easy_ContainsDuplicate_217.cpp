//Some Optimal Solution :

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                return true;
            }
        }
        
        return false;
    }
};

//My Solution : 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<int, int> mymap;
        map<int, int> :: iterator iter;

        for(int i = 0; i < nums.size(); i++)
        {
            mymap[nums[i]]++;
        }
        for(iter = mymap.begin(); iter != mymap.end(); iter++)
        {
            if((*iter).second > 1)
            {
                return true;
            }
        }
        return false;
    }
};