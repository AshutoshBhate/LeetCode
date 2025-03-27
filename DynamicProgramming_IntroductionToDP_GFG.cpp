class Solution {
    public:
    
      const long long mod = 1000000007;
      
      
      long long topDownHelper(int n, vector<long long>& dp)
      {
          if(n <= 1)
          {
              return n;
          }
          
          if(dp[n] != -1)
          {
              return dp[n];
          }
          
          dp[n] = (topDownHelper(n - 1, dp) + topDownHelper(n - 2, dp)) % mod;
          return dp[n];
      }
      
      long long int topDown(int n)
      {
          vector<long long> dp(n + 1, -1);
          
          return topDownHelper(n, dp);
      }
      
      long long int bottomUp(int n)
      {
          long long pred2 = 0;
          long long pred1 = 1;
          long long curr = n;
          
          for(int i = 2; i <= n; i++)
          {
              curr = (pred2 + pred1) % mod;
              pred2 = pred1;
              pred1 = curr;
              
          }
          
          return curr;
      }
  };