class Solution {
public:
    int addDigits(int num)
    {
        int result = INT_MAX;
        int single = num%10;
        int remaining = num/10;

        if(remaining == 0)
        {
            return single;
        }

        result = single + addDigits(remaining);

        if(result > 9)
        {
            result = addDigits(result);
        }
        
        return result;
    }
};