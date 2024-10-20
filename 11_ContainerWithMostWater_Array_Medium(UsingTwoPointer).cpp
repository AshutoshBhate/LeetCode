class Solution {
public:
    int maxArea(vector<int>& height)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, right = height.size() - 1, min_num, max_area = 0, multiplication;

        while(left < right)
        {
            min_num = min(height[left], height[right]);
            multiplication = min_num * (right - left);
            max_area = max(max_area, multiplication);

            if(height[left] > height[right])
            {
                right = right - 1;
            }
            else
            {
                left = left + 1;
            }
        }

        return max_area;
    }
};