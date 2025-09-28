//My Approach : 

class Solution {
  public:
    bool isMaxHeap(int arr[], int n)
    {
        if(n % 2 == 0)
        {
            arr[n] = INT_MIN;
        }
        
        int new_arr[n + 2];
        
        for(int i = 0; i <= n; i++)
        {
            new_arr[i + 1] = arr[i];
        }
        
        new_arr[0] = 0;
        
        for(int i = 1; i <= n/2; i++)
        {
            if(new_arr[i] < new_arr[2 * i] || new_arr[i] < new_arr[2 * i + 1])
            {
                return false;
            }
        }
        
        return true;
    }
};

//ChatGPT Approach : 

class Solution {
  public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i <= (n - 2) / 2; i++)
        {
            // Left child index
            int left = 2 * i + 1;
            // Right child index
            int right = 2 * i + 2;

            // If left child exists and is greater than parent
            if (left < n && arr[i] < arr[left])
            {
                return false;
            }
                
            // If right child exists and is greater than parent
            if (right < n && arr[i] < arr[right])
            {
                return false;
            }       
        }

        return true;
    }
};