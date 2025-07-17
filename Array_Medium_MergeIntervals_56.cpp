class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(intervals.begin(), intervals.end(),
                  [](vector<int>& a, vector<int>& b)
                  {
                    return a[0] < b[0];
                  });
        
        vector<vector<int>> answers;

        int inner_min = intervals[0][0], outer_max = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= outer_max)
            {
                if(intervals[i][1] > outer_max)
                {
                    outer_max = intervals[i][1];
                }
            }
            else
            {
                vector<int> sub_answer = {inner_min, outer_max};
                answers.push_back(sub_answer);

                inner_min = intervals[i][0];
                outer_max = intervals[i][1];
            }
        }

        vector<int> sub_answer = {inner_min, outer_max};
        answers.push_back(sub_answer);
        
        return answers;
    }
};