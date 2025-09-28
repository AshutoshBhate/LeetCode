class Solution {
    public:
        bool areOccurrencesEqual(string s)
        {
            cin.tie(nullptr);
            cout.tie(nullptr);
            ios::sync_with_stdio(0);
    
            unordered_map<char, int> string_catch;
    
            for(int i = 0; i < s.size(); i++)
            {
                string_catch[s[i]]++;
            }
    
            // int common = string_catch.begin() -> second;
            // for(auto iter : string_catch)
            // {
            //     if(iter.second != common)
            //     {
            //         return false;
            //     }
            // }
    
            for(auto iter = string_catch.begin(); iter != string_catch.end(); iter++)
            {
                auto next_it = std :: next(iter);
                if(next_it != string_catch.end() && iter -> second != next_it -> second)
                {
                    return false;
                }
            }
    
            return true; 
        }
    };