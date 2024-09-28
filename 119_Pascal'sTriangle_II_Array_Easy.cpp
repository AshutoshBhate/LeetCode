class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int row = rowIndex + 1;
        vector<int> answer;
        long long ans = 1;

        answer.push_back(ans);
        for(int i = 1; i < row; i++)
        {
            ans = ans * (row - i);
            ans = ans/i;
            answer.push_back(ans);
        }
        
        return answer;
    }
};