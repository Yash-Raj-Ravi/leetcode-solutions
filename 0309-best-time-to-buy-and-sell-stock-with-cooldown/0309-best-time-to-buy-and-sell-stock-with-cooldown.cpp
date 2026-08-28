// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int buy,vector<int>& prices)
//     {
//         int n = prices.size();
//         if(idx>=n) return 0;

//         int maxProfit=-1e9;

//         if(buy)
//         {
//             maxProfit = max(-prices[idx] + solve(idx+1,0,prices), solve(idx+1,1,prices));
//         }
//         else
//         {
//             maxProfit = max(prices[idx] + solve(idx+2,1,prices), solve(idx+1,0,prices));
//         }
//         return maxProfit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         return solve(0,1,prices);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int solve(int idx,int buy,vector<int>& prices,vector<vector<int>> &dp)
//     {
//         int n = prices.size();
//         if(idx>=n) return 0;

//         if(dp[idx][buy]!=-1) return dp[idx][buy];

//         int maxProfit=-1e9;

//         if(buy)
//         {
//             maxProfit = max(-prices[idx] + solve(idx+1,0,prices,dp), solve(idx+1,1,prices,dp));
//         }
//         else
//         {
//             maxProfit = max(prices[idx] + solve(idx+2,1,prices,dp), solve(idx+1,0,prices,dp));
//         }
//         return dp[idx][buy] = maxProfit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }
// };

// 3.Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int maxProfit = 0;
                if(buy){
                    maxProfit = max(-prices[idx] + dp[idx+1][0],dp[idx+1][1]); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
                }

                else // buy==0, Already bought now its time to sell
                {
                    maxProfit = max(prices[idx] + dp[idx+2][1],dp[idx+1][0]); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
                }

                dp[idx][buy] = maxProfit;
            }
        }
    return dp[0][1];
    }
};