// // 1.Recursion
// class Solution {
// private:
//     int solve(int idx,int buy,vector<int>& prices)
//     // buy=1 means you are allowed to buy since you are holding any stock
//     // buy=0 means you are not allowed to buy since you are holding a stock
//     {
//         // Base cases
//         int n = prices.size();
//         if(idx==n) return 0;

//         int maxProfit = 0;
//         if(buy){
//             maxProfit = max(-prices[idx] + solve(idx+1,0,prices),solve(idx+1,1,prices)); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
//         }

//         else // buy==0, Already bought now its time to sell
//         {
//             maxProfit = max(prices[idx] + solve(idx+1,1,prices),solve(idx+1,0,prices)); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
//         }
    
//         return maxProfit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
       
//         return solve(0,1,prices);
//     }
// };

// 2.Memoization
class Solution {
private:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>> &dp)
    // buy=1 means you are allowed to buy since you are holding any stock
    // buy=0 means you are not allowed to buy since you are holding a stock
    {
        // Base cases
        int n = prices.size();
        if(idx==n) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int maxProfit = 0;
        if(buy){
            maxProfit = max(-prices[idx] + solve(idx+1,0,prices,dp),solve(idx+1,1,prices,dp)); // buy becomes 0 in first instance after buying one stock since you can't buy further it is sold and prices[idx] is subtracted in profit since buying has to be subtracted from selling to get profit
        }

        else // buy==0, Already bought now its time to sell
        {
            maxProfit = max(prices[idx] + solve(idx+1,1,prices,dp),solve(idx+1,0,prices,dp)); // 1st instance is of selling which leads to buy=1 since you are allowed to buy after selling while 2nd instance is of continuing to other day without selling the stock in order to look for better profit.
        }
    
        return dp[idx][buy] = maxProfit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//     }
// };