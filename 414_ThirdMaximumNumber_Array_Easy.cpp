class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        set<int> mySet;
        vector<int> :: iterator iter;
        set<int> :: reverse_iterator it = mySet.rbegin();

        sort(nums.begin(), nums.end());
        for(iter = nums.begin(); iter != nums.end(); iter++)
        {
            mySet.insert(*iter);
        }

        if(mySet.size() >= 3)
        {
            for(int i = 0; i < 2; i++)
            {
                it++;
            }
            return *(it);
        }
        else
        {
            return *(it);
        }
    }
};