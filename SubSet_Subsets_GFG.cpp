class Solution {
  public:
  
    void helper(int index, vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr)
    {
        /*
        When index == arr.size(), we've made a decision (include or exclude) for every element. 
        At that point, the current subset 'ds' is complete and can be added to 'ans' — 
        regardless of how many elements it contains.
        */

        if(index == arr.size())
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[index]);
        
        //Pick
        helper(index + 1, ans, ds, arr);

        //Not Pick
        ds.pop_back();
        helper(index + 1, ans, ds, arr);
        
    }
  
    vector<vector<int>> subsets(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(0, ans, ds, arr);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};