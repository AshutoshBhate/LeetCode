class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<int> ans(boxes.size(), 0);

        int moves = 0, balls = 0;
        for(int i = 0; i < boxes.size(); i++)
        {
            ans[i] = moves + balls;
            moves = moves + balls;
            balls = balls + (boxes[i] - '0');
        }

        moves = 0, balls = 0;
        for(int i = boxes.size() - 1; i>= 0; i--)
        {
            ans[i] += moves + balls;
            moves = moves + balls;
            balls = balls + (boxes[i] - '0');
        }

        return ans;
    }
};