//GeeksForGeeks:

map<int, int> preSumMap; // to store the prefix sum and its first occurrence
    int sum = 0; // stores the cumulative sum
    int maxLen = 0; // stores the length of the longest subarray
    
    for (int i = 0; i < N; i++) {
        // Add the current element to the cumulative sum
        sum += A[i];
        
        // If the sum is equal to K, update the maxLen (subarray starts from 0)
        if (sum == K) {
            maxLen = max(maxLen, i + 1);
        }
        
        // Calculate the remaining sum (sum - K) to find a subarray that sums to K
        int rem = sum - K;
        
        // If rem exists in the map, calculate the length of the subarray and update maxLen
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        
        // Store the current sum in the map if it doesn't exist already
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    
    return maxLen;


//Striver:

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

