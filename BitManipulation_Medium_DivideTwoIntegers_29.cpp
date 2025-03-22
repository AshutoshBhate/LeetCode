class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if(dividend == divisor)
        {
            return 1;
        }
       
        bool sign = true;

        if(dividend >= 0 && divisor < 0)
        {
            sign = false;
        }
        if(dividend < 0 && divisor > 0)
        {
            sign = false;
        }

        long dividend_new  = abs(long(dividend));
        long divisor_new = abs(long(divisor));
        long ans = 0;

        while(dividend_new >= divisor_new)
        {
            int count = 0;
            while(dividend_new >= (divisor_new << (count + 1)))
            {
                count++;
            }

            ans += 1 << count;
            dividend_new -= (divisor_new << count);
        }

        if(ans == (INT_MAX) && sign == true)
        {
            return INT_MAX;
        }
        if(ans == (INT_MAX) && sign == false)
        {
            return (-1 * INT_MAX);
        }
        if(ans == INT_MIN && sign == true)
        {
            return INT_MAX;
        }

        return sign ? ans : (-1 * ans);
    }
};