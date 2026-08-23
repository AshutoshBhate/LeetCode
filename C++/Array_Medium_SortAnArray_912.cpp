class Solution {
    void mergeHalves(vector<int>& arr, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high)
    {
        if(low >= high)
        {
            return;
        }

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeHalves(arr, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int>& nums)
    {
        if(nums.size() > 1)
        {
            mergeSort(nums, 0, nums.size() - 1);
        }
        return nums;
    }
};
