class Solution {
public:
    string reverseWords(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int i = 0;
        int n = s.size();
        string result = "";

        while(i < n)
        {
            while(i < n && s[i] == ' ')
            {
                i++;
            }
            if(i >= n)
            {
                break;
            }
            int j = i + 1;
            while(j < n && s[j] != ' ')
            {
                j++;
            }

            string word = s.substr(i, j - i);   //Arguments are the starting point and distance

            if(result.length() == 0)
            {
                result = word;
            }
            else
            {
                result = word + " " + result;
            }
            i = j + 1;
        }

        return result;
    }
};