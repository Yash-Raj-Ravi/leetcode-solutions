// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int target,vector<int>& nums)
//     {
//         if(idx==0) 
//         {
//             if(nums[0]==0 && target==0) return 2;
//             if(nums[idx]==abs(target)) return 1;
//             else return 0;
//         }

//         // Take +
//         int pos = solve(idx-1,target-nums[idx],nums); // Target can become negative at some point
//         // Take -
//         int neg = solve(idx-1,target+nums[idx],nums);
//     return (pos + neg);
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return solve(n-1,target,nums);
//     }
// };

// 2.Memoization
class Solution {
private:
    int solve(int idx,int target,vector<int>& nums,vector<vector<int>> &dp,int offset)
    {
        if(idx==0) 
        {
            if(nums[0]==0 && target==0) return 2;
            if(nums[idx]==abs(target)) return 1;
            else return 0;
        }
         // Target went outside [-sum, +sum]
        if(target + offset < 0 || target + offset >= dp[0].size())
            return 0;

        if(dp[idx][target+offset]!=-1) return dp[idx][target+offset];

        // Take +
        int pos = solve(idx-1,target-nums[idx],nums,dp,offset); // Target can become negative at some point
        // Take -
        int neg = solve(idx-1,target+nums[idx],nums,dp,offset);
    return dp[idx][target+offset] = (pos + neg);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum) return 0;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return solve(n-1,target,nums,dp,sum);
    }
};


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//     }
// };