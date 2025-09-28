class Solution {
public:
    string convertDateToBinary(string date)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string number = "";
        int digit = 0;
        string push = "";
        string answer = "";
        int count = 0;

        for(int i = 0; i <= date.size(); i ++)
        {

            if(date[i] == '-' || i == date.size())
            {
                digit = stoi(number);
                bitset<16> binary(digit);
                push = binary.to_string();

                int j = 0;
                while(push[j] != '1')
                {
                    count++;
                    j++;
                }
                push.erase(0, count);
                count = 0;

                answer += push;

                if(i != date.size())
                {
                    answer += '-';
                }
                number.clear();

                continue;
            }

            number += date[i];
        }

        return answer;
    }
};