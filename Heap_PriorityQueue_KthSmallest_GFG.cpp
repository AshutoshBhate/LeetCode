// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i = 0; i < arr.size(); i++)
        {
            minHeap.push(arr[i]);
        }
        
        for(int j = 0; j < k - 1; j++)
        {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};