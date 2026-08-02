// // 1.Memoization
// class Solution {
// private:
//     int solve(int idx,vector<int> &dp,const vector<int> &nums)
//     {
//         int n = nums.size();
//         // Base case: Forward Memoization
//         if(idx>=n) return 0; // Since if houses are existing say till index 4 then nothing can be robbed from index 5 onwards.

//         if(dp[idx]!=-1) return dp[idx];

//         int rob = nums[idx] + solve(idx+2,dp,nums);
//         int skip = solve(idx+1,dp,nums);
        
//     return dp[idx] = max(rob,skip);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return solve(0,dp,nums);
//     }
// };

// // 2.Tabulation
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2,0);
//         dp[n]=0; dp[n+1]=0;
//         for(int i=n-1;i>=0;i--)
//         {
//            int rob = nums[i] + dp[i+2]; 
//            int skip = dp[i+1]; 
//            dp[i] = max(rob,skip);
//         }

//     return dp[0];
//     }
// };

// 3.Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next=0;
        int furthernext=0;
        for(int i=n-1;i>=0;i--)
        {
            int rob = nums[i] + furthernext;
            int skip = next;
            int curr = max(skip,rob);
            furthernext = next;
            next = curr;
        }
        return next;
    }
};