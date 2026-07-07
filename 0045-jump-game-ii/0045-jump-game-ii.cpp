// // 1.Brute
// class Solution {
// public:

// int helper(vector<int>& nums,int pos)
// {
//     int n = nums.size();
//     int minJump=INT_MAX;
//     if(pos >= n-1) return 0;

//     if(nums[pos]==0) return INT_MAX;

//     for(int jump=1;jump<=nums[pos];jump++)
//     {
//         int subresult = helper(nums,pos+jump);

//         if(subresult!=INT_MAX)
//         {
//             minJump = min(minJump,1+subresult);
//         }
//     }
// return minJump;
// }
//     int jump(vector<int>& nums) {
//         return helper(nums,0);
//     }
// };

// 2.Better (DP-Array)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,INT_MAX); // Stores min jumps required to reach each index
//         dp[0]=0;

//         for(int i=0;i<n;i++)
//         {
//             for(int j=1;j<=nums[i] && i+j<n; j++){
//             dp[i+j] = min(dp[i+j],dp[i]+1);
//             }
//         }
//         return dp[n-1];
//     }
// };

// 3.Optimal (Greedy)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps=0, currEnd=0, farthest=0;
        for(int i=0;i<n-1;i++)
        {
            farthest = max(farthest,i+nums[i]);
            if(i==currEnd)
            {
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
    }
};