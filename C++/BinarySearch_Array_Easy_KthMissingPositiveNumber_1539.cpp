//Brute Force

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        for(int i = 0; i < arr.size(); i++)
        {
            if(k >= arr[i])
            {
                k++;
            }
            else
            {
                break;
            }
        }

        return k;
    }
};

//Optimal : Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int low = 0, high = arr.size() - 1;

        while(low <= high)
        {
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low + k;
    }
};