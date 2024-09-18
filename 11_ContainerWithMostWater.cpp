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
            if((*iter).second > static_cast<int>(abs((*iter).second - static_cast<int>((index_adjust.size() - 1)))))
            {
                multiplication = (*iter).second * (*iter).first;

            }
            else
            {
                multiplication = static_cast<long>(abs((*iter).second - static_cast<long>((index_adjust.size() - 1)))) * (*iter).first;
            }
            index_adjust.erase((*iter).second);

            // auto it = index_adjust.find((*iter).second);
            // if (it != index_adjust.end()) {
            //     index_adjust.erase(it);
            // }

            if( multiplication > super_multiplication)
            {
                super_multiplication = multiplication;
            }
        }

        return super_multiplication;
    }
};