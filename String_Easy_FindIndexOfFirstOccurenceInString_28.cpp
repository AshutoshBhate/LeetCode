#include<bits/stdc++.h>
#include<string>

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        auto it = haystack.find(needle);    //it here doesn't point like an iterator, it instead returns the  
        if(it != string::npos)              //integer index of first occurence         
        {
            return it;
        }
        else
        {
            return -1;
        }   

        return 0; 
    }

};