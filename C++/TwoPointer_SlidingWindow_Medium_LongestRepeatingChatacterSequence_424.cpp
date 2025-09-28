class Solution {
public:
    int characterReplacement(string s, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int left_pointer = 0, right_pointer = 0, maxFreq = 0, maxLen = 0;
        int hash[26] = {0};

        while(right_pointer < s.size())
        {
            hash[s[right_pointer]-'A']++; // Character frequency

            if(hash[s[right_pointer]-'A'] > maxFreq)
            {
                maxFreq = hash[s[right_pointer]-'A'];
            }

            if((right_pointer - left_pointer + 1) - maxFreq > k) //Replaced 'while' with 'if'. As it has to be just within k
            {
                hash[s[left_pointer]-'A']--;

                /* We omit this as there is no point in trimming maxFreq. 
                   Decreasing frequency won't contribute to the longest answer
                */
               
                // for(int i = 0; i <= 25; i++)    .
                // {
                //     maxFreq = min(maxFreq, hash[s[left_pointer]-'A']);
                // }

                left_pointer++;     //Trimming the left portion
            }

            maxLen = max(maxLen, right_pointer - left_pointer + 1);
            right_pointer++;
        }

        return maxLen;
    }
};