class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection_array;
        set<int> mySet;
        //set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(intersection_array));
        
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(mySet, mySet.begin()));
        intersection_array.assign(mySet.begin(), mySet.end());
        
        return intersection_array;
    }
};