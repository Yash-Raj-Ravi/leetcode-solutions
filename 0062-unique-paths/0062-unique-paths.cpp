// 1.Memoization
class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp){

        if(m==0 && n==0) return 1; // Since a path must have been taken to reach (0,0) from (m-1,n-1).
        if(m<0 || n<0) return 0; // If any direction boundary is surpassed before reaching (0,0) then return 0.

        if(dp[m][n]!=-1) return dp[m][n];
        int up = solve(m-1,n,dp); // We are solving from (m-1,n-1) to (0,0).
        int left = solve(m,n-1,dp);

        return dp[m][n] = (up+left);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
        
//     }
// };


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
        
//     }
// };