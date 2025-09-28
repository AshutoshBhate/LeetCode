//Not Optimal (Recursion) : My Approach

class Solution {
    public:
    
        long long mod = 1000000007;
    
        int helper(long long n)
        {
            if(n == 0)
            {
                return 5;
            }
    
            if(((n - 1) % 2) != 0)
            {
                return (helper(n - 1) * 5LL) % mod;
            }
            else
            {
                return (helper(n - 1) * 4LL) % mod;
            }
    
            return 0;
        }
    
        int countGoodNumbers(long long n)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(false);

            n = n - 1;

            return helper(n);
        }
};

//Not Optimal (Recursion) : GPT Approach

class Solution {
    public:
        long long mod = 1000000007;
    
        long long helper(long long remaining, long long ans)
        {
            if (remaining == 0)
            {
                return ans;
            }
    
            long long multiplier;
    
            if (((remaining - 1) % 2) != 0)
            {
                multiplier = 5LL;
            }
            else
            {
                multiplier = 4LL;
            }
    
            return helper(remaining - 1, (ans * multiplier) % mod);
        }
    
        int countGoodNumbers(long long n)
        {
            return helper(n - 1, 5);
        }
};

//iterative Modular Exponentiation Method:

class Solution {
    public:
        
        long long mod = 1000000007;
        
        int countGoodNumbers(long long n)
        {
            // Calculate exponents for 5 and 4
            long long exponentFive = (n + 1) / 2;
            long long exponentFour = n / 2;
            
            long long resultFive = 1;
            long long resultFour = 1;
            long long base;
            
            // Calculate 5^exponentFive % mod iteratively
            base = 5;
            
            while (exponentFive > 0)
            {
                if ((exponentFive % 2) == 1)
                {
                    resultFive = (resultFive * base) % mod;
                }
                
                base = (base * base) % mod;
                exponentFive = exponentFive / 2;
            }
            
            // Calculate 4^exponentFour % mod iteratively
            base = 4;
            
            while (exponentFour > 0)
            {
                if ((exponentFour % 2) == 1)
                {
                    resultFour = (resultFour * base) % mod;
                }
                
                base = (base * base) % mod;
                exponentFour = exponentFour / 2;
            }
            
            long long ans = (resultFive * resultFour) % mod;
            
            return ans;
        }
};
    

