class Solution {
public:
    int findPermutationDifference(string s, string t)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
    
        int answer = 0;

        for(int i = 0; i < s.size(); i++)
        {
            answer += abs(i - int(t.find(s[i])));
        }

        return answer;
    }
};