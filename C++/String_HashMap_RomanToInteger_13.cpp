class Solution
{
public:
    int romanToInt(string s)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        unordered_map<char, int> romanMap;

        romanMap['I'] = 1;    
        romanMap['V'] = 5;    
        romanMap['X'] = 10;    
        romanMap['L'] = 50;    
        romanMap['C'] = 100;    
        romanMap['D'] = 500;    
        romanMap['M'] = 1000;

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int currentValue = romanMap[s[i]];

            if (i + 1 < n && currentValue < romanMap[s[i+1]])
            {
                total -= currentValue;
            }
            else
            {
                total += currentValue;
            }
        }
        return total;
    }
};