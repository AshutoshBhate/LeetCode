vector<int> GenerateRow(int row)
{
    vector<int> answer;
    int ans = 1;
    answer.push_back(ans);
    for(int column = 1; column < row; column++)
    {
        ans = ans * (row - column);
        ans = ans / column;
        answer.push_back(ans);
    }
    return answer;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<vector<int>> Pascal;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> temp = GenerateRow(i);
            Pascal.push_back(temp);
        }
        return Pascal;
    }
};