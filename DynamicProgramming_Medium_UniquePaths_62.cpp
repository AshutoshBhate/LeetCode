class Solution {
    public:
        int uniquePaths(int m, int n)
        {
            int a = m + n - 2;
            int k = min(m - 1, n - 1);
    
            long result = 1;
    
            for (int i = 0; i < k; ++i)
            {
                result = result * (a - i) / (i + 1);
            }
            
            return static_cast<int>(result);
        }
    };
    