class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int m = matrix.size();
        int n = matrix[0].size();

        int vertical_up = 0, vertical_down = m - 1;
        int horizontal_left = 0, horizontal_right = n - 1;

        while(vertical_up <= vertical_down)
        {
            int vertical_mid = (vertical_up + vertical_down) / 2;

            if(target < matrix[vertical_mid][0])
            {
                vertical_down = vertical_mid - 1;
            }
            else if(target > matrix[vertical_mid][n - 1])
            {
                vertical_up = vertical_mid + 1;
            }
            else
            {
                while(horizontal_left <= horizontal_right)
                {
                    int horizontal_mid = (horizontal_left + horizontal_right) / 2;

                    if(matrix[vertical_mid][horizontal_mid] <= target)
                    {
                        horizontal_left = horizontal_mid + 1;
                    }
                    else
                    {
                        horizontal_right = horizontal_mid - 1;
                    }
                }

                if(matrix[vertical_mid][horizontal_right] == target)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

        return false;
    }
};