class Solution {
  public:
  
    int lowerBound(vector<int>& single_arr, int find)
    {
        int n = single_arr.size();
        int ans = n;
        int right = 0;
        int left = n - 1;
        
        while(right <= left)
        {
            int mid = (left + right)/2;
            
            if(single_arr[mid] >= find)
            {
                ans = mid;
                left = mid - 1;
            }
            else
            {
                right = mid + 1;
            }
        }
        
        return ans;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int count_max = 0;
        int max_index = -1;
        
        int current_count = 0;
        
        for(int i = 0; i < n; i++)
        {
            current_count = arr[i].size() - lowerBound(arr[i], 1);
            
            if(current_count > count_max)
            {
                count_max = current_count;
                max_index = i;
            }
        }
        
        return max_index;
        
    }
};