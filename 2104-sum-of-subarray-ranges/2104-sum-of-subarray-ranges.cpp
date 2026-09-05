// 1.Brute
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int start=0;start<n;start++){
            int mini = 1e9;
            int maxi = -1e9;
            for(int end=start;end<n;end++)
            {
                mini = min(mini,nums[end]);
                maxi = max(maxi,nums[end]);
                ans+= maxi-mini;
            }
         
        }
        return ans;
    }
};


// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
        
//     }
// };