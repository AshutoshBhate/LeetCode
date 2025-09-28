class Solution {
public:

    void merge(vector<int>& arr, int low, int mid, int high, int& count_reverse)
    {
        vector<int> temp;

        int left = low, right = mid + 1;

        while(right <= high && left <= mid)
        {
            if((long long)arr[left] > 2LL * arr[right])
            {
                count_reverse += (mid - left + 1);
                right++;
            }
            else
            {
                left++;
            }
        }
        
        
        int i = low, j = mid + 1;
        while(i <= mid && j <= high)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= high)
        {
            temp.push_back(arr[j]);
            j++;
        }

        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void MS(vector<int>& arr, int low, int high, int& count_reverse)
    {
        if(low == high)
        {
            return;
        }
        int mid = (low + high)/2;

        MS(arr, low, mid, count_reverse);
        MS(arr, mid + 1, high, count_reverse);

        merge(arr, low, mid, high, count_reverse);
    }

    int reversePairs(vector<int>& nums)
    {
        int count_reverse = 0;
        MS(nums, 0, nums.size() - 1, count_reverse);

        return count_reverse;
    }
};