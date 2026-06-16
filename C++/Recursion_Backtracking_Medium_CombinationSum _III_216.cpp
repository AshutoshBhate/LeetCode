class Solution {
public:

    void helper(vector<vector<int>>& answer, vector<int>& current_answer, int num_left, int sum, int start_number)
    {
        if(num_left == 0 && sum == 0)
        {
            answer.push_back(current_answer);
            return;
        }
        if(num_left == 0 && sum != 0)
        {
            return;
        }
        if(sum < 0)
        {
            return;
        }
        
        for(int i = start_number; i <= 9; i++)
        {
            if(i > sum)
            {
                break;
            }

            current_answer.push_back(i);

            helper(answer, current_answer, num_left - 1, sum - i, i + 1);

            current_answer.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios :: sync_with_stdio(false);

        vector<vector<int>> answer;
        vector<int> current_answer;

        int start_number = 1;

        helper(answer, current_answer, k, n, start_number);

        return answer;
    }
};