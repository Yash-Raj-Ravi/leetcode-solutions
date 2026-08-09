// // 1.Memoization
// class Solution {
// private:
//     int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp)
//     {
//         if(i==0 && j==0) return grid[0][0];
//         if(i<0 || j<0) return INT_MAX; // Since when going out of bouundary, return a very large value so the path is not considered for min path requirement.

//         if(dp[i][j]!=-1) return dp[i][j];

//         int up = solve(i-1,j,grid,dp);
//         int left = solve(i,j-1,grid,dp);

//         return dp[i][j] = grid[i][j] + min(up,left); // Take the current grid cell value before moving up or left.
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,grid,dp);
//     }
// };

// // 2.Tabulation
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));

//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0 && j==0) dp[i][j]=grid[i][j];
//                 else
//                 {
//                     int up=INT_MAX,left=INT_MAX;
//                     if(i>0) up = dp[i-1][j];
//                     if(j>0) left = dp[i][j-1];
//                     dp[i][j] = grid[i][j] + min(up,left);
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// 3.Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);

        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) curr[j]=grid[i][j];
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = grid[i][j] + min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
