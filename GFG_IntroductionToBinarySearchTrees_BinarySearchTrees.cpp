class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr)
    {
        int x, y, size = arr.size();
        for(int i = 0; i < size - 1; i++)
        {
            if(arr[i + 1] < arr[i] || arr[i + 1] == arr[i]) //Should be strictly increasing
            {
                return false;
            }
        }
        
        return true;
    }
};