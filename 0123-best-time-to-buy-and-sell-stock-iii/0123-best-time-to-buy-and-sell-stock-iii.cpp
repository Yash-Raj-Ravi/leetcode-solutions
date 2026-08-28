// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int buy,int transactions,vector<int>& prices)
//     {
//         int n = prices.size();
//         // Base cases
//         if(idx==n) return 0;
//         if(transactions==2) return 0;

//         int maxProfit = -1e9;

//         if(buy)
//         {
//            maxProfit = max(-prices[idx] + solve(idx+1,0,transactions,prices),solve(idx+1,1,transactions,prices));
//         }
//         else // Time to sell
//         {
//             maxProfit = max(prices[idx] + solve(idx+1,1,transactions+1,prices),solve(idx+1,0,transactions,prices));
//         }
//     return maxProfit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         return solve(0,1,0,prices);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int solve(int idx,int buy,int transactions,vector<int>& prices,vector<vector<vector<int>>> &dp)
//     {
//         int n = prices.size();
//         // Base cases
//         if(idx==n) return 0;
//         if(transactions==2) return 0;

//         if(dp[idx][buy][transactions]!=-1) return dp[idx][buy][transactions];

//         int maxProfit = -1e9;

//         if(buy)
//         {
//            maxProfit = max(-prices[idx] + solve(idx+1,0,transactions,prices,dp),solve(idx+1,1,transactions,prices,dp));
//         }
//         else // Time to sell
//         {
//             maxProfit = max(prices[idx] + solve(idx+1,1,transactions+1,prices,dp),solve(idx+1,0,transactions,prices,dp));
//         }
//     return dp[idx][buy][transactions] = maxProfit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
//         return solve(0,1,0,prices,dp);
//     }
// };

// 3.Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));

     for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                for(int transactions=0;transactions<2;transactions++)
                {
                int maxProfit = -1e9;

                if(buy)
                {
                    maxProfit = max(-prices[idx] + dp[idx+1][0][transactions],dp[idx+1][1][transactions]);
                }
                else // Time to sell
                {
                    maxProfit = max(prices[idx] + dp[idx+1][1][transactions+1],dp[idx+1][0][transactions]);
                }
            dp[idx][buy][transactions] = maxProfit;
                }
            }
        }
        return dp[0][1][0];
    }
};