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

        int i = 0, j = 0, count = 0;
        while(i < g.size() && j < s.size())
        {
            if(g[i] <= s[j])
            {
                i++;
                j++;
                count++;
            }
            else
            {
                j++;
            }
        }

        return count;
    }
};
