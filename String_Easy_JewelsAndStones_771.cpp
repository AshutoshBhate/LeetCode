class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        
        for (char stone : stones)
        {
            for (char jewel : jewels)
            {
                if (stone == jewel)
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};