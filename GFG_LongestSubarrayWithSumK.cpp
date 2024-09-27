//Striver: Same code will also run for negatives, same logic  will run
//O(n^2)
//SC: As we are storing every prefix sum: O(n)
//You cannot optimize this code further if the array contains nrgatives and positves both

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
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
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions: For the correct lenght for an array: 2, 0, 0, 0, 3
        if (preSumMap.find(sum) == preSumMap.end()) //If sum not there previously, then only update the index
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len <<"\n";
    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Now the optimal solution for all positives and zeros:
//Hashmaps have O(1) best case and O(n) worst case
//Maps have average time O(log n)

#include<bits/stdc++.h>
using namespace std;


int getLongestSubarray(vector<int>& a, long long k)
{
   int maxLen = 0, right = 0, left = 0;
   int sum = a[0];
    int n = a.size();

//Two while loops, O(n)? Its actually O(2n)
//The outer while loop is running till n. So a O(n)
//The second (inner) outer loop is not actually running whole length all the time


    while(right < n)        
    {
        while(left <= right && sum > k)
        {
            sum = sum - a[left];
            left++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n)
        {
            sum = sum + a[right];
        }
    }

    return maxLen;
}



