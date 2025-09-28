class Solution {
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> consonants;    
        unordered_map<char, int> vowels;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowels[s[i]]++;
            }
            else
            {
                consonants[s[i]]++;
            }
        }

        int cons_max = 0;
        int vow_max = 0;

        for(auto iter = consonants.begin(); iter != consonants.end(); iter++)
        {
            if(cons_max < (*iter).second)
            {
                cons_max = (*iter).second;
            }
        }

        for(auto iter = vowels.begin(); iter != vowels.end(); iter++)
        {
            if(vow_max < (*iter).second)
            {
                vow_max = (*iter).second;
            }
        }

        return cons_max + vow_max;
    }
};