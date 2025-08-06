class Solution {
public:
    int numberOfSubstrings(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        map<char, int> myMap = {{'a', 0}, {'b', 0}, {'c', 0}};
        int count = 0;
        int i = 0;

        for (int j = 0; j < s.size(); ++j)
        {
            myMap[s[j]]++;

            while (myMap['a'] > 0 && myMap['b'] > 0 && myMap['c'] > 0)
            {
                count += s.size() - j;
                myMap[s[i]]--;
                i++;
            }
        }

        return count;
    }
};
