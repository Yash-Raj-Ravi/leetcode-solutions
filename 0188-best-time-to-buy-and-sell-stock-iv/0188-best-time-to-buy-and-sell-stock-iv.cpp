// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int buy,int transactions,vector<int>& prices,int k)
//     {
//         int n = prices.size();
//         // Base cases
//         if(idx==n) return 0;
//         if(transactions==k) return 0;

//         int maxProfit = -1e9;

//         if(buy)
//         {
//            maxProfit = max(-prices[idx] + solve(idx+1,0,transactions,prices,k),solve(idx+1,1,transactions,prices,k));
//         }
//         else // Time to sell
//         {
//             maxProfit = max(prices[idx] + solve(idx+1,1,transactions+1,prices,k),solve(idx+1,0,transactions,prices,k));
//         }
//     return maxProfit;
//     }
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         return solve(0,1,0,prices,k);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int solve(int idx,int buy,int transactions,vector<int>& prices,int k,vector<vector<vector<int>>> &dp)
//     {
//         int n = prices.size();
//         // Base cases
//         if(idx==n) return 0;
//         if(transactions==k) return 0;

//         if(dp[idx][buy][transactions]!=-1) return dp[idx][buy][transactions];

//         int maxProfit = -1e9;

//         if(buy)
//         {
//            maxProfit = max(-prices[idx] + solve(idx+1,0,transactions,prices,k,dp),solve(idx+1,1,transactions,prices,k,dp));
//         }
//         else // Time to sell
//         {
//             maxProfit = max(prices[idx] + solve(idx+1,1,transactions+1,prices,k,dp),solve(idx+1,0,transactions,prices,k,dp));
//         }
//     return dp[idx][buy][transactions] = maxProfit;
//     }
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k,-1)));
//         return solve(0,1,0,prices,k,dp);
//     }
// };
 
// // 3.Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));

     for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                for(int transactions=0;transactions<k;transactions++)
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

// // 4.Space Optimization
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> ahead(2,vector<int> (3,0));
//         vector<vector<int>> curr(2,vector<int> (3,0));

//      for(int idx=n-1;idx>=0;idx--)
//         {
//             for(int buy=1;buy>=0;buy--)
//             {
//                 for(int transactions=0;transactions<2;transactions++)
//                 {
//                 int maxProfit = -1e9;

//                 if(buy)
//                 {
//                     maxProfit = max(-prices[idx] + ahead[0][transactions],ahead[1][transactions]);
//                 }
//                 else // Time to sell
//                 {
//                     maxProfit = max(prices[idx] + ahead[1][transactions+1],ahead[0][transactions]);
//                 }
//             curr[buy][transactions] = maxProfit;
//                 }
//             }
//             ahead = curr;
//         }
//         return ahead[1][0];
//     }
// };