//Time Limit Exceeded

class Solution {
public:
    double myPow(double x, int n)
    {
        bool flag = false;
        double cascade = 0;

        if(n < 0)
        {
            flag = true;
        }

        if(n == 1)
        {
            return x;
        }
        if(n == 0)
        {
            return 1;
        }

        n = abs(n);

        cascade = x * myPow(x, n - 1);

        if(flag == true)
        {
            return 1/cascade;
        }
        return cascade;
        
        return 0;
    }
};

//Optimal

class Solution {
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0)
        {
            nn = -1 * nn;
        }
        while(nn)
        {
            if(nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn /2;
            }
        }
        if(n<0)
        {
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};