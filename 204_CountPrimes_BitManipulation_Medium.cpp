//Naive Solution

class Solution {
public:
    int count = 0;
    int countPrimes(int n)
    {
        int x = n - 1;

        for(int i = x; i > 1; i--)
        {
            bool flag = true;
            for(int j = sqrt(i); j > 1; j--)
            {
                if(i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                count++;
            }
        }
        return count;
    }
};

//Optimal Solution

class Solution {
public:
    int countPrimes(int n)
    {
        vector<int> prime(n, 1); 
        int count = 0;

        if (n <= 2)
        {
            return 0;
        }

        for(int i = 2; i * i < n; i++)
        {
            if(prime[i] == 1)
            {
                for(int j = i*i; j < n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }

        for(int i = 2; i < n; i++)
        {
            if(prime[i] == 1)
            {
                count++;
            }
        }

        return count;
    }
};