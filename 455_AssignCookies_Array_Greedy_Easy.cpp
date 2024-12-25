//Brute Force:

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        int count = 0;

        sort(s.begin(), s.end());
        for(int i = 0; i < g.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(g[i] <= s[j])
                {
                    count++;
                    s.erase(s.begin() + j);
                    break;
                }
            }
        }

        return count;
    }
};

//Better:

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int greed_pointer = 0, satisfy_pointer = 0, count = 0;
        while(greed_pointer < g.size() && satisfy_pointer < s.size())
        {
            if(g[greed_pointer] <= s[satisfy_pointer])
            {
                greed_pointer++;
                satisfy_pointer++;
                count++;
            }
            else
            {
                satisfy_pointer++;
            }
        }

        return count;
    }
};