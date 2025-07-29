class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        vector<int> answer;

        int repeat_element = nums[0];
        int count = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != repeat_element)
            {
                answer.push_back(repeat_element);
                repeat_element = nums[i];
            }
        }
        answer.push_back(nums[nums.size() - 1]);
        
        for(int i = 1; i < answer.size() - 1; i++)
        {
            if(answer[i - 1] < answer[i] && answer[i + 1] < answer[i])
            {
                count++;
            }
            if(answer[i - 1] > answer[i] && answer[i + 1] > answer[i])
            {
                count++;
            }
        }

        return count;
    }
};