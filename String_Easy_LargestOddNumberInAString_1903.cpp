// class Solution {
// public:
//     string largestOddNumber(string num)
//     {
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//         ios::sync_with_stdio(false);

//         string number_string = {}, tempno = {}, answer;

//         for(long long i = 0; i < num.size(); i++)
//         {
//             number_string = number_string + num[i];

//             if(num[i] % 2 != 0)
//             {
//                 tempno = number_string;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         if(tempno.length() == 0)
//         {
//             return {};
//         }
//         else
//         {
//             answer = tempno;
//             return answer;
//         }
//     }
// };

class Solution {
public:
    string largestOddNumber(string num)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        for (long long i = num.size() - 1; i >= 0; --i)
        {
            if (num[i] % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        
        return {};
    }
};
