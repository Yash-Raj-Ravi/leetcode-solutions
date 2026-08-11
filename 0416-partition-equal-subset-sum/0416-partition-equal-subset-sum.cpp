// // 1.Recursion
// class Solution {
// private:
//     bool solve(int idx,int target,vector<int>& nums)
//     {
//         int n = nums.size();
//         if(target==0) return true;
//         if(idx==n) return false;

//         // Skip
//         bool notTake = solve(idx+1,target,nums);
//         // Take
//         bool Take = false;
//         if(target>=nums[idx]) Take = solve(idx+1,target-nums[idx],nums);

//         return Take||notTake;
//     }
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%2==1) return false;
//         return solve(0,sum/2,nums);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     bool solve(int idx,vector<int>& nums,int target,vector<vector<int>> &dp)
//     {
//         int n = nums.size();
//         // Base case:
//         if(target==0) return true;
//         if(idx == 0) return target==nums[0];

//         if(dp[idx][target]!=-1) return dp[idx][target];
//         // skip the value at arr[idx]
//         bool notTake = solve(idx-1,nums,target,dp);
//         // Take the value at arr[idx]
//         bool take = false; 
//         if(target>=nums[idx])
//           take = solve(idx-1,nums,target-nums[idx],dp);
//     return dp[idx][target] = take || notTake; // Since target can be achived in either case.

//     }
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%2==1) return false;
//         vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1)); 
//         return solve(n-1,nums,sum/2,dp);
//     }
//  };

// // 3.Tabulation
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(),nums.end(),0);
//         if(sum%2==1) return false;
//         int target = sum/2;
//         vector<vector<bool>> dp(n,vector<bool>(target+1,0));
//         for(int i=0;i<n;i++) dp[i][0] = true; // If at any index of the array, target becomes zero then return true.
//         if(nums[0] <= target) dp[0][nums[0]] = true;

//         for(int idx=1;idx<n;idx++)
//         {
//             for(int j=1;j<=target;j++)
//             {
//                 bool notTake = dp[idx-1][j];
//                 // Take the value at arr[idx]
//                 bool take = false; 
//                 if(j>=nums[idx])
//                 take = dp[idx-1][j-nums[idx]];
//                 dp[idx][j] = (take || notTake); 
//             }
//         }
//     return dp[n-1][target];
//     }
// };

// 4.Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        // For optimizing space, we don't need all rows rather only the previous row 
        // Size taken is target+1 since it represents numbers of columns while n is for rows.
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target = sum/2;
        vector<bool> prev(target+1,0);
        vector<bool> curr(target+1,0);
        prev[0] = curr[0] = true; 
        if(nums[0]<=target) prev[nums[0]] = true;

        for(int idx=1;idx<n;idx++)
        {
            for(int j=1;j<=target;j++)
            {
                bool notTake = prev[j];
                // Take the value at arr[idx]
                bool take = false; 
                if(j>=nums[idx])
                take = prev[j-nums[idx]];
                curr[j] = (take || notTake); 
            }
            prev = curr;
        }
    return prev[target];
    }
};