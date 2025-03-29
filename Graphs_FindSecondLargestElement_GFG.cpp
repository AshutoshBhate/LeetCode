class Solution {
  public:
    // Function returns the second largest elements
    int print2largest(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        vector<int> :: iterator iter;
        int biggest_element  = arr[arr.size() - 1];
        
        for(auto iter = arr.begin(); iter != arr.end(); iter++)
        {
            if(*iter == biggest_element && arr[0] != arr[arr.size()-1])
            {
                return *(iter - 1);
            }
            if(iter == arr.end())
            {
                return -1;
            }
            if(arr[0] == arr[arr.size()-1])
            {
                return -1;
            }
        }
    }
};