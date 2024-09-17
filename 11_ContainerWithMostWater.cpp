class Solution {
public:
    int maxArea(vector<int>& height)
    {
        map<int, int> height_adjust;
        map<int, int> index_adjust;
        map<int, int> :: iterator iter;
        long multiplication = 0, super_multiplication = 0;

        for(int i = 0; i < height.size(); i++)
        {
            height_adjust[height[i]] = i;
            index_adjust[i] = height[i];
        }
        for(iter = height_adjust.begin(); iter != height_adjust.end(); iter++)
        {
            if(abs((*iter).second - 0) > abs((*iter).second - (index_adjust.size() - 1)))
            {
                multiplication = index_adjust[0] * (*iter).first;
            }
            else
            {
                multiplication = index_adjust[index_adjust.size() - 1] * (*iter).first;
            }
            if( multiplication > super_multiplication)
            {
                super_multiplication = multiplication;
            }
        }

        return super_multiplication;
    }
};