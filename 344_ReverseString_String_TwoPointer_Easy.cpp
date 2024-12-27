class Solution {
public:
    void reverseString(vector<char>& s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        char temp;
        int i = 0, j = s.size() - 1;

        while(i < j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
    }
};