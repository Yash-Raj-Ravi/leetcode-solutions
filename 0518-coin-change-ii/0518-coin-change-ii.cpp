// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int amount, vector<int>& coins)
//     {
//         if(amount==0) return 1;
//         if(amount<0) return 0;
//         if(idx==0) {
//             if(amount % coins[0] == 0) return 1;
//             else return 0;
//         }
//         // Skip
//         int skip = solve(idx-1,amount,coins);
//         // Take
//         int Take = solve(idx,amount-coins[idx],coins); // Stay at same idx since we have infinite supply of coins.

//         return (Take+skip);
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return solve(n-1,amount,coins);
//     }
// };

// 2.Memoization
class Solution {
private:
    int solve(int idx,int amount, vector<int>& coins,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
            if(amount<0) return 0;
        if(idx==0) {
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        // Skip
        int skip = solve(idx-1,amount,coins,dp);
        // Take
        int Take = solve(idx,amount-coins[idx],coins,dp); // Stay at same idx since we have infinite supply of coins.

        return dp[idx][amount] = (Take+skip);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};



// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return solve(n-1,amount,coins);
//     }
// };
