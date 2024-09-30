class Solution {
public:
    int arrangeCoins(int n)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int count = 0, i = 1;
        int no_change = n;
       
        while(n > 0 && i <= no_change)
        {
            n -= i;
            count++;
            i++;
            if(n < 0)
            {
                count--;
                break;
            }
        } 

        return count;  
    }
};