class Solution 
{
public:
    string decodeMessage(string key, string message) 
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        unordered_map<char, char> mapping;
        char current_alpha_char = 'a';

        for (char k : key) 
        {
            if (k != ' ' && mapping.find(k) == mapping.end()) 
            {
                mapping[k] = current_alpha_char;
                current_alpha_char++;
            }
        }
        
        string decoded_message = "";
        
        for (char m : message) 
        {
            if (m == ' ') 
            {
                decoded_message += ' ';
            } 
            else 
            {
                decoded_message += mapping[m];
            }
        }
        
        return decoded_message;
    }
};