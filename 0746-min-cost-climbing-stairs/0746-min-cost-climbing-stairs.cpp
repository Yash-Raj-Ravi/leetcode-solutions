// 1.Recursion
// class Solution {
// private:
//     int solve(int i,vector<int>& cost)
//     {
//         int n = cost.size();
//         if(i>=n) return 0;

//         return min(cost[i] + solve(i+1,cost),cost[i] + solve(i+2,cost));

//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return min(solve(0,cost),solve(1,cost));
//     }
// };

// 2.Memoization
class Solution {
private:
    int solve(int i,vector<int>& cost,vector<int> &dp)
    {
        int n = cost.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i] = min(cost[i] + solve(i+1,cost,dp),cost[i] + solve(i+2,cost,dp));

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};