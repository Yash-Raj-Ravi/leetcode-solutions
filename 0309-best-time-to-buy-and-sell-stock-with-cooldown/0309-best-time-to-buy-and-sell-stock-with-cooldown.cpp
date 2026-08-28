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

// 2.Memoization
class Solution {
private:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>> &dp)
    {
        int n = prices.size();
        if(idx>=n) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        int maxProfit=-1e9;

        if(buy)
        {
            maxProfit = max(-prices[idx] + solve(idx+1,0,prices,dp), solve(idx+1,1,prices,dp));
        }
        else
        {
            maxProfit = max(prices[idx] + solve(idx+2,1,prices,dp), solve(idx+1,0,prices,dp));
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