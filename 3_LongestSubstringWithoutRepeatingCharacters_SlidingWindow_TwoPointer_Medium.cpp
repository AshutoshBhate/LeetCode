class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, length = 0, max_length = 0;
        unordered_map<char, int> myMap;

        while(j < s.size())
        {
            auto it = myMap.find(s[j]);

            if(it != myMap.end())
            {
                if(i <= myMap[s[j]])
                {
                    i = ((*it).second) + 1;
                }
                myMap[s[j]] = j;

            }
            else
            {
                myMap[s[j]] = j;
            }
            length = j - i + 1;
            max_length = max(max_length, length);

            j++;
        }
        return max_length;
    }
};