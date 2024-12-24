//Striver Solution

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k)
{
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    //apply binary search:
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k))
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}


//My Solution

class Solution {
public:

    int min_number = INT_MAX;
    int max_number = INT_MIN;

    int findMin(vector<int>& array_1)
    {
        for(int i = 0; i < array_1.size(); i++)
        {
            min_number = min(min_number, array_1[i]);
        }

        return min_number;
    }
    
    int findMax(vector<int>& array_2)
    {
        for(int i = 0; i < array_2.size(); i++)
        {
            max_number = max(max_number, array_2[i]);
        }
       
        return max_number;
    }

    bool compute(vector<int>& array_3, int middle_num, int m, int k)
    {
        int num_boq = 0, total_num_boq = 0, count = 0;

        for(int d = 0; d < array_3.size(); d++)
        {
            if(middle_num >= array_3[d])
            {
                count++;
            }
            else
            {
                num_boq = count / k;
                total_num_boq = total_num_boq + num_boq;

                count = 0;
            }
        }
        num_boq = count / k;
        total_num_boq = total_num_boq + num_boq;

        if(total_num_boq >= m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        if((long long) m * (long long) k > bloomDay.size())
        {
            return -1;
        }
        
        int i = findMin(bloomDay);
        int j = findMax(bloomDay);

        while(i <= j)
        {
            int mid = (i + j)/2;

            if(compute(bloomDay, mid, m, k))
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        return i;
    }
};


