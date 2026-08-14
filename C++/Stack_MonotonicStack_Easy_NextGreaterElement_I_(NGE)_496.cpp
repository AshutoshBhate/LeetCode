/*
[NGE] (Already completed)
  │
  ▼
Phase 1: Next Smaller Element (NSE)  ──► Keeps direction (right), flips operator
  │
  ▼
Phase 2: Previous Greater Element (PGE)  ──► Keeps condition (greater), flips direction (left)
  │
  ▼
Phase 3: Previous Smaller Element (PSE)  ──► Flips both (left + smaller)
  │
  ▼
Phase 4: Combined Bounds (NSE + PSE)  ──► The interview standard (Histogram & Subarrays)
*/

/*
 * Key Pattern: Two-Array Query Problem (Hash Map)
 * - Phase: Next Greater Element (NGE) -> Right-to-Left Traversal
 * - Why Hash Map: The problem gives us a main array (nums2) and a random query array (nums1).
 *   We map value -> answer so we can answer nums1 queries in O(1) time.
 * - Note: This is an EXCEPTION. It only works because the problem guarantees unique values.
 *   For single-array problems, always use direct indexing.
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> next_greater_element(nums2.size(), -1);

        stack<int> myStack;
        map<int, int> myMap;
        vector<int> answer;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!myStack.empty() && nums2[i] >= myStack.top())
            {
                myStack.pop();
            }
            if (!myStack.empty())
            {
                next_greater_element[i] = myStack.top();
            }

            myStack.push(nums2[i]);
        }

        for(int i = 0; i < nums2.size(); i++)
        {
            myMap[nums2[i]] = next_greater_element[i];
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            answer.push_back(myMap[nums1[i]]);
        }

        return answer;
    }
};