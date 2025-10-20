class Solution {
  public:
    vector<int> sieve(int n)
    {
        vector<int> prime(n + 1, true);
        
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(prime[i] == true)
            {
                for(int j = i * i; j <= n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        
        vector<int> answer;
        
        for(int p = 2; p <= n; p++)
        {
            if(prime[p])
            {
                answer.push_back(p);
            }
        }
        
        return answer;
    }
};