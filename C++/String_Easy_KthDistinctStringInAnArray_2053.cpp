class Solution {
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> myMap;

        for(int i = 0; i < arr.size(); i++)
        {
            myMap[arr[i]]++;
        }

        for(int i = 0; i < arr.size(); i++)
        {
            if(myMap[arr[i]] == 1 && k > 1)
            {
                k--;
            }
            else if(myMap[arr[i]] == 1 && k == 1)
            {
                return arr[i];
            }
        }

        return "";
    }
};