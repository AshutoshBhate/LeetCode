#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high, int& count_inversions)
    {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                count_inversions += mid - left + 1;
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void MS(vector<int>& arr, int low, int high, int& count_inversions)
    {
        if (low >= high) return;

        int mid = (low + high) / 2;

        MS(arr, low, mid, count_inversions);
        MS(arr, mid + 1, high, count_inversions);

        merge(arr, low, mid, high, count_inversions);
    }

    int inversionCount(vector<int>& arr)
    {
        int count_inversions = 0;
        MS(arr, 0, arr.size() - 1, count_inversions);
        return count_inversions;
    }
};
