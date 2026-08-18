// We have an infinite number of each kind of coin so we will stand at same index after the coin is taken.

// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int amount,vector<int>& coins)
//     {
//         if(idx==0){
//             if(amount % coins[idx]==0) return amount/coins[idx];
//             else return 1e9;
//         }
//         // Skip
//         int skip = solve(idx-1,amount,coins);
//         // Take
//         int Take = INT_MAX;
//         if(amount>=coins[idx]) Take = 1 + solve(idx,amount-coins[idx],coins); // Stand on same index

//         return min(Take,skip);

//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         int ans = solve(n-1,amount,coins);
//         if(ans>=1e9) return -1;
//         else
//         return ans;
        
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int solve(int idx,int amount,vector<int>& coins,vector<vector<int>> &dp)
//     {
//         if(idx==0){
//             if(amount % coins[idx]==0) return amount/coins[idx];
//             else return 1e9;
//         }
//         if(dp[idx][amount]!=-1) return dp[idx][amount];
//         // Skip
//         int skip = solve(idx-1,amount,coins,dp);
//         // Take
//         int Take = INT_MAX;
//         if(amount>=coins[idx]) Take = 1 + solve(idx,amount-coins[idx],coins,dp); // Stand on same index

//         return dp[idx][amount] = min(Take,skip);

//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         int ans = solve(n-1,amount,coins,dp);
//         if(ans>=1e9) return -1;
//         else
//         return ans;
        
//     }
// };

// // 3.Tabulation
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,0));

//         for(int k=0;k<=amount;k++){
//         if(k % coins[0]==0) dp[0][k] = k/coins[0];
//         else dp[0][k] = 1e9;
//         }

//         // for(int i=0;i<n;i++) dp[i][0] = 0;

//         for(int idx=1;idx<n;idx++)
//         {
//             for(int j=1;j<=amount;j++)
//             {
//         // Skip
//         int skip = dp[idx-1][j];
//         // Take
//         int Take = INT_MAX;
//         if(j>=coins[idx]) Take = 1 + dp[idx][j-coins[idx]]; // Stand on same index

//         dp[idx][j] = min(Take,skip);
//             }
//         }
//         int ans = dp[n-1][amount];
//         if(ans>=1e9) return -1;
//         else
//         return ans;
//     }
// };

// 4.Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int k=0;k<=amount;k++){
        if(k % coins[0]==0) prev[k] = k/coins[0];
        else prev[k] = 1e9;
        }

        // for(int i=0;i<n;i++) dp[i][0] = 0;

        for(int idx=1;idx<n;idx++)
        {
            for(int j=1;j<=amount;j++)
            {
        // Skip
        int skip = prev[j];
        // Take
        int Take = INT_MAX;
        if(j>=coins[idx]) Take = 1 + curr[j-coins[idx]]; // Stand on same index

        curr[j] = min(Take,skip);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans>=1e9) return -1;
        else
        return ans;
    }
};