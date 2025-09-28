class Solution {
public:
    string defangIPaddr(string address)
    {
        char target = '.';
        string replacement = "[.]";

        string answer;
        
        int i = 0;
        while(i != address.size())
        {
            if(address[i] != target)
            {
                answer.push_back(address[i]);
            }
            else
            {
                answer += replacement;
            }
            
            i++;
        }   

        return answer; 
    }
};