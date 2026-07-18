class Solution {
  public:
  
    int mergeHalves(vector<int>& arr, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        int count = 0;
        vector<int> temp;
        
        while(left <= mid && right <= high)
        {
            if(arr[left] > arr[right])
            {
                count += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
            else
            {
                temp.push_back(arr[left]);
                left++;
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
        
        return count;
    }
    
    int mergeSort(vector<int>& arr, int low, int high)
    {
        int count = 0;
        
        if(low >= high)
        {
            return 0;
        }
        
        int mid = int((low + high)/2);
        
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += mergeHalves(arr, low, mid, high);
        
        return count;
        
    }
  
    int inversionCount(vector<int> &arr)
    {
        int count = 0;
        int low = 0;
        int high = arr.size() - 1;
        
        count = mergeSort(arr, low, high);
        
        return count;
        
    }
};