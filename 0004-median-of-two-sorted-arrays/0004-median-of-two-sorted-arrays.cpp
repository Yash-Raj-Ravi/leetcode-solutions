// 1.Brute
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        long double ans=-1;
        vector<int> merged;
        
        for(auto x:nums1)
        {
            merged.push_back(x);
        }
        for(auto x:nums2)
        {
            merged.push_back(x);
        }
        sort(merged.begin(),merged.end());

        int sz = merged.size();
        if(sz%2!=0)
        {
            ans = merged[sz/2];
        }
        else
        {
            ans = (merged[(sz-1)/2] + merged[sz/2])/2.0;
        }
        return ans;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//     }
// };