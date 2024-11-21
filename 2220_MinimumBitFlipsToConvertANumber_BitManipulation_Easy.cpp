class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        start = start ^ goal;

        bitset<32> s(start);

        int count = s.count();

        return count;
    }
};