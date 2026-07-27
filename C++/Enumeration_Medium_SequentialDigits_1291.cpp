class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> answer;
        int low_digit = to_string(abs(low)).length(), high_digit = to_string(abs(high)).length();

        for(int i = low_digit; i <= high_digit; i++)
        {
            for(int j = 1; j < 9; j++)
            {
                if (i + j > 10)
                {
                    break;
                }

                int num = j;
                int prev = j;

                for(int k = 0; k < i - 1; k++)
                {
                    num = num * 10;
                    prev = prev + 1;
                    num = num + prev;
                }
                if(num >= low && num <= high)
                {
                    answer.push_back(num);
                }
            }
        }

        return answer;
    }
};