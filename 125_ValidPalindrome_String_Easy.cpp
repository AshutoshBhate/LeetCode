#include<bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        // vector<char> result;
        string result;

        for(char c : s)
        {
            if(isalnum(c))
            {
                result.push_back(c);
            }
        }
        
        transform(result.begin(), result.end(), result.begin(), ::tolower);

        int left = 0, right = result.size() - 1;
        while(left < right)
        {
            if(result[left] != result[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;


        //while(left < right)
        //{
        //    // Skip non-alphabetic characters
        //    while(left < right && !isalnum(s[left])) left++;
        //    while(left < right && !isalnum(s[right])) right--;
        //
        //     // Compare alphabetic characters, case-insensitive
        //     if(tolower(s[left]) != tolower(s[right]))
        //     {
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;
    }
};