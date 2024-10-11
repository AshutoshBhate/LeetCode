class Solution {
public:
    int reverse(int x)
    {
        string answer = {};
        answer = to_string(x);
        std :: reverse(answer.begin(), answer.end());
        long y = stol(answer);
        if(y >= pow(2, 31) || y < -1 * pow(2, 31))
        {
            return 0;
        }
        else
        {
            if(x < 0)
            {
                y = y * -1;
            }
            return y;
        }  
    }
};