// User function Template for C++
class Solution {
  public:
    long long count(int n)
    {
        
        long long count = 1;
        
        for(long long i = 1; i <= n - 1; i++)
        {
            count *= pow(2, i);
        }
        
        return count;
    }
};