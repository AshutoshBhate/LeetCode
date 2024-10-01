//Time Limit Exceeded

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        unordered_map<char, int> myMap;
        unordered_map<char, int> :: iterator iter;
        string str;

        for(int i = 0; i < strs.size(); i++)
        {
            for(int j = 0; j < strs[i].size(); j++)
            {
                myMap[strs[i][j]]++;
            }
        }
        iter = myMap.begin();
        int number = (*iter).second;
        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            while(number >= (*iter).second)
            {
                str.push_back((*iter).first);
            }
        }
        return str;
    }
};

//Optimal

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        string ans="";
        int n = strs.size();

        sort(strs.begin(),strs.end());

        string first = strs[0], last = strs[n-1];
        for(int i=0; i < min(first.size(), last.size()); i++)
        {
            if(first[i]!= last[i])
            {
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};