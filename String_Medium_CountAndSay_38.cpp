class Solution {
public:

    string RLE(string y)
    {
        int i = 0;
        string ans = "";

        while(i < y.size())
        {
            int count = 1;
            char currentChar = y[i];

            while(i + 1 < y.size() && currentChar == y[i + 1])
            {
                count++;
                i++;
            }
            ans += (to_string(count));
            ans += currentChar;

            i++;
        }

        return ans;
    }

    string helper(int n)
    {
        if(n == 1)
        {
            return "1";
        }

        string j = "1";
        string k;

        for(int i = 2; i <= n; i++)
        {
            k = RLE(j);
            j = k;
        }

        return k;
    }

    string countAndSay(int n)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        return helper(n);
    }
};