//My Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> unique_set;

        for(int i = 0; i < nums.size(); i++)
        {
            unique_set.insert(nums[i]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0, max_count = 0, prev_num = 0;

        if(unique_set.empty())
        {
            return 0;
        }

        for (int num : unique_set)
        {
            pq.push(num);
        }
        
        while(1)
        {
            prev_num = pq.top();
            pq.pop();

            if(pq.empty())
            {
                max_count = max(max_count, count);
                return max_count + 1;
            }

            if(pq.top() == prev_num + 1)
            {
                count++;
            }
            else
            {
                max_count = max(max_count, count);
                count = 0;
            }
        }
    }
};

//Striver Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int longest = 1;

        unordered_set<int> st;

        // put all the array elements into set:
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        // Find the longest sequence:
        for (auto it : st)
        {
            // if 'it' is a starting number:
            if (st.find(it - 1) == st.end()) // Checking whether 'it' has any previous element
            {
                // find consecutive numbers:
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    count = count + 1;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

