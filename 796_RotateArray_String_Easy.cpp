class Solution {
public:
    bool rotateString(string s, string goal)
    {  
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int m = s.size();
        int n = goal.size();
        if(m != n) return false;

        for(int i=0; i <m; i++)
        {
            s = s.substr(1) + s[0];     //Basically removes the first character
            if(s == goal) return true;
        }
        return false;
    }
};