class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(0);

        int five = 0, ten = 0;

        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                five++;
            }
            if(bills[i] == 10)
            {
                if(five >= 1)
                {
                    ten++;
                    five--;
                }
                else
                {
                    return false;
                }
            }
            if(bills[i] == 20)
            {
                if(five >= 1 && ten >= 1)
                {
                    five--;
                    ten--;
                }
                else if(five >= 3)
                {
                    five = five - 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};