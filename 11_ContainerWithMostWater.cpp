class Solution {
public:
    int maxArea(vector<int>& height)
    {
        multimap<int, int> height_adjust;
        multimap<int, int> index_adjust;
        multimap<int, int> :: iterator iter;
        long multiplication = 0, super_multiplication = 0;

        for(int i = 0; i < height.size(); i++)
        {
            height_adjust.emplace(height[i], i);
            index_adjust.emplace(i, height[i]);
        }

        for(iter = height_adjust.begin(); iter != height_adjust.end(); iter++)
        {
            auto lastElement = index_adjust.rbegin();
            int lastKey = lastElement->first;

            auto firstElement = index_adjust.begin();
            int firstKey = firstElement->first;

            if(static_cast<long long>(abs(((*iter).second - firstKey))) > (static_cast<int>(abs((*iter).second - lastKey))))
            {
                multiplication = static_cast<long long>(abs(((*iter).second - firstKey))) * (*iter).first;
            }
            else
            {
                multiplication = static_cast<long>(abs((*iter).second - lastKey)) * (*iter).first;
            }
            index_adjust.erase((*iter).second);

            if( multiplication > super_multiplication)
            {
                super_multiplication = multiplication;
            }
        }

        return super_multiplication;
    }
};