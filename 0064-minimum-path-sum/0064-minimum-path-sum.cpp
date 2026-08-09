// 1.Memoization
class Solution {
private:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX; // Since when going out of bouundary, return a very large value so the path is not considered for min path requirement.

        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(i-1,j,grid,dp);
        int left = solve(i,j-1,grid,dp);

        return dp[i][j] = grid[i][j] + min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//     }
// };


// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//     }
// };