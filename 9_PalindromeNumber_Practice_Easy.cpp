class Solution {
public:
    bool isPalindrome(int x)
    {
        string answer;
        string check;

        answer = to_string(x);
        check = answer;
        reverse(check.begin(), check.end());

        if(check == answer)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};