class Solution {
    public:
        void findCombination(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds)
        {
            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }
    
            for (int i = index; i < candidates.size(); i++)
            {
                if (i > index && candidates[i] == candidates[i - 1]) //To consider the first element of the fresh recursion even if previous element prior (Which we aren't even considering) to first element turns out to be the same element
                {
                    continue;
                }
                if (candidates[i] > target)
                {
                    break;
                }
                    
                ds.push_back(candidates[i]);
                findCombination(i + 1, target - candidates[i], candidates, ans, ds);
                ds.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            sort(candidates.begin(), candidates.end());
    
            vector<vector<int>> ans;
            vector<int> ds;
    
            findCombination(0, target, candidates, ans, ds);
    
            return ans;
        }
    };