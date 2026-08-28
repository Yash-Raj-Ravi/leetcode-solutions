// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int buy,vector<int>& prices,int fee)
//     // buy=1 means you are allowed to buy since you are holding any stock
//     // buy=0 means you are not allowed to buy since you are holding a stock
//     {
//         // Base cases
//         int n = prices.size();
//         if(idx==n) return 0;

//         int maxProfit = 0;
//         if(buy){
//             maxProfit = max(-fee - prices[idx] + solve(idx+1,0,prices,fee),solve(idx+1,1,prices,fee)); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
//         }

//         else // buy==0, Already bought now its time to sell
//         {
//             maxProfit = max(prices[idx]  + solve(idx+1,1,prices,fee),solve(idx+1,0,prices,fee)); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
//         }
    
//         return maxProfit;
//     }

// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         return solve(0,1,prices,fee);
//     }
// };

// 2.Memoization
class Solution {
private:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>> &dp,int fee)
    // buy=1 means you are allowed to buy since you are holding any stock
    // buy=0 means you are not allowed to buy since you are holding a stock
    {
        // Base cases
        int n = prices.size();
        if(idx==n) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        int maxProfit = 0;
        if(buy){
            maxProfit = max(- fee -prices[idx] + solve(idx+1,0,prices,dp,fee),solve(idx+1,1,prices,dp,fee)); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
        }

        else // buy==0, Already bought now its time to sell
        {
            maxProfit = max(prices[idx] + solve(idx+1,1,prices,dp,fee),solve(idx+1,0,prices,dp,fee)); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
        }
    
        return dp[idx][buy] = maxProfit;
    }

public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
    }
};

// // 3.Tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
        
//         for(int idx=n-1;idx>=0;idx--)
//         {
//             for(int buy=1;buy>=0;buy--)
//             {
//                 int maxProfit = 0;
//                 if(buy){
//                     maxProfit = max(-prices[idx] + dp[idx+1][0],dp[idx+1][1]); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
//                 }

//                 else // buy==0, Already bought now its time to sell
//                 {
//                     maxProfit = max(prices[idx] + dp[idx+1][1],dp[idx+1][0]); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
//                 }

//                 dp[idx][buy] = maxProfit;
//             }
//         }
//     return dp[0][1];
//     }
// };

// 4.Space Optimization
// We are filling dp table from last row to front and each upper row requires only the row below it for getting filled.
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> ahead(2,0), curr(2,0);
        
//         for(int idx=n-1;idx>=0;idx--)
//         {
//             for(int buy=1;buy>=0;buy--)
//             {
//                 int maxProfit = 0;
//                 if(buy){
//                     maxProfit = max(-prices[idx] + ahead[0],ahead[1]); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
//                 }

//                 else // buy==0, Already bought now its time to sell
//                 {
//                     maxProfit = max(prices[idx] + ahead[1],ahead[0]); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
//                 }

//                 curr[buy] = maxProfit;
//             }
//             ahead = curr;
//         }
//     return ahead[1];
//     }
// };

// // 5.Space Optimization (Using 4 variables in place 2 arrays of size 2 each.)

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int aheadBuy=0,aheadNotbuy=0;
//         int currBuy=0,currNotbuy=0;
        
//         for(int idx=n-1;idx>=0;idx--)
//         {
    
//             currBuy = max(-prices[idx] + aheadNotbuy,aheadBuy); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
        

//             currNotbuy = max(prices[idx] + aheadBuy,aheadNotbuy); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
            
//             aheadBuy = currBuy;
//             aheadNotbuy = currNotbuy;
//         }
//     return aheadBuy;
//     }
// };