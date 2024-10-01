//Brute Force

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int i;

        for(i = 0; i < nums.size(); i ++)
        {
            if((i == 0 || nums[i - 1] < nums[i]) && i == nums.size() - 1 || nums[i + 1] < nums[i])
            {
                return i;
            }
        }

        return i;
    }
};

//Better

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left = 0, right = nums.size() - 1, mid;

        while(left <= right)
        {
            mid =  (left + right)/2;
            if(mid == 0 || mid == nums.size() - 1)
            {
                auto maxElement = max_element(nums.begin(), nums.end());
                return distance(nums.begin(), maxElement);
            }
            else
            {
                if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
                {
                    return mid;
                }
                else
                {
                    if(nums[mid - 1] > nums[mid])
                    {
                        right  = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
        }
        return mid;
    }
};

//Optimal

class Solution{
public:
    int findPeakElement(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // Dummy return statement
        return -1;
    }
};



