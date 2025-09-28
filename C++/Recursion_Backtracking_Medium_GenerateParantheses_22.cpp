class Solution {
public:
    void helper(vector<string>& answer, int n, vector<int>& current_made, int open_count, int close_count)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        if(open_count == n && close_count == n)
        {
            string s = "";

            for(int i = 0; i < current_made.size(); i++)
            {
                if(current_made[i] == 1)
                {
                    s += '(';
                }
                else
                {
                    s += ')';
                }
            }

            answer.push_back(s);

            return;
        }

        if(current_made.size() == 2 * n)
        {
            return;
        }

        if(open_count < n)
        {
            current_made.push_back(1);
            helper(answer, n, current_made, open_count + 1, close_count);
            current_made.pop_back();
        }
        
        if(open_count > close_count)
        {
            current_made.push_back(-1);
            helper(answer, n, current_made, open_count, close_count + 1);
            current_made.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> answer;
        vector<int> current_made;
        int open_count = 0, close_count = 0;

        helper(answer, n, current_made, open_count, close_count);

        return answer;
    }
};