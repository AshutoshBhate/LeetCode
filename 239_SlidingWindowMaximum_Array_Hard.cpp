//Time Limit Exceeded

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int i = 0, j = k - 1;
        vector<int> answer;
        int current_max = 0;

        while(j <= nums.size() - 1)
        {
            auto it = max_element(nums.begin() + i, nums.begin() + j + 1);
            answer.push_back(*it);       
            i++;
            j++;     
        }
        
        return answer;
    }
};

//Optimal: Utilizing Dequeue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
         return ans;
    }
};