// 1.Memoization
class Solution {
private:
    int solve(int idx,vector<int> &dp,const vector<int> &nums)
    {
        int n = nums.size();
        // Base case: Forward Memoization
        if(idx>=n) return 0; // Since if houses are existing say till index 4 then nothing can be robbed for index 5 onwards.

        if(dp[idx]!=-1) return dp[idx];

        int rob = nums[idx] + solve(idx+2,dp,nums);
        int skip = solve(idx+1,dp,nums);
        
    return dp[idx] = max(rob,skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,dp,nums);
    }
};


// class Solution {
// public:
//     int rob(vector<int>& nums) {
        
//     }
// };


// class Solution {
// public:
//     int rob(vector<int>& nums) {
        
//     }
// };