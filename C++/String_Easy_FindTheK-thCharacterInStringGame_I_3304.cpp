class Solution {
public:
    char kthCharacter(int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        string answer = "a";

        while(answer.size() < k)
        {
            string temp = "";

            for(int i = 0; i < answer.size(); i++)
            {
                temp += (char)(answer[i] + 1);
            }

            answer += temp;
        }  

        return answer[k - 1];  
    }
};