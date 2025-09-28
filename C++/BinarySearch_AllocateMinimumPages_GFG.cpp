class Solution {
  public:
  
    int countStudents(vector<int>& arr, int mid)
    {
        int curr_Page = 0, students = 1;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(curr_Page + arr[i] <= mid)
            {
                curr_Page += arr[i];
            }
            else
            {
                students++;
                curr_Page = arr[i];
            }
        }
        
        return students;
    }
  
    int findPages(vector<int> &arr, int k)
    {
        if(k > arr.size())
        {
            return -1;
        }
        
        int low = *(max_element(arr.begin(), arr.end()));   //max_element returns an iterator
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(countStudents(arr, mid) <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return low;
        
    }
};