//This code works for both negative and positive values : Cannot optimize further if array contains both negative and positive values

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k)
    {
        map<int, int> PreSumMap;
        
        int PreSum = 0, len = 0, max_length = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            PreSum += arr[i];
            
            if(PreSum == k)
            {
                max_length = max(max_length, i + 1);
            }
            
            long long remaining = PreSum - k;
            
            if(PreSumMap.find(remaining) != PreSumMap.end())
            {
                int len = i - PreSumMap[remaining];
                max_length = max(max_length, len);
            }
            
            if(PreSumMap.find(PreSum) == PreSumMap.end())
            {
                PreSumMap[PreSum] = i;
            }
        }
        
        return max_length;
    }
};

//TC: O(N * (If using map log : N))
//    O(N * (If using unordered_map : N)) worst time if we have a lot of collisions, O(N * (If using unordered_map : 1)) if no collisions
//SC: O(N)


//Now the optimal solution for all positives and zeros :

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k)
    {
        int max_length = 0, right = 0, left = 0;
        int sum = arr[0];
        int n = arr.size();
    
    
        while(right < n)        
        {
            while(left <= right && sum > k)
            {
                sum = sum - arr[left];
                left++;
            }
            if(sum == k)
            {
                max_length = max(max_length, right - left + 1);
            }
            right++;
            if(right < n)
            {
                sum = sum + arr[right];
            }
        }
    
        return max_length;
    }
};

//TC: O(2N)
//SC: O(1)



