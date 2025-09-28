//My Solution : 

class Solution {
public:
    int beautySum(string s)
    {
        string curr_string = "";
        int count = 0;

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                curr_string += s[j];

                map<char, int> myMap;

                for(char c : curr_string)
                {
                    myMap[c]++;
                }

                int max_freq = 0;
                int min_freq = INT_MAX;

                for(auto it : myMap)
                {
                    if(it.second > max_freq)
                    {
                        max_freq = it.second;
                    }
                    if(it.second < min_freq)
                    {
                        min_freq = it.second;
                    }
                }

                if(max_freq - min_freq < 0)
                {
                    continue;
                }
                else
                {
                    count += (max_freq - min_freq);
                }
            }

            curr_string = "";
        }    

        return count;
    }
};

//Gemini Solution : 

class Solution {
public:
    int beautySum(std::string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            vector<int> frequency(26, 0);

            for (int j = i; j < s.size(); j++)
            {
                frequency[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int k = 0; k < 26; k++)
                {
                    if (frequency[k] > 0)
                    {
                        maxFreq = max(maxFreq, frequency[k]);
                        minFreq = min(minFreq, frequency[k]);
                    }
                }

                count += (maxFreq - minFreq);
            }
        }

        return count;
    }
};