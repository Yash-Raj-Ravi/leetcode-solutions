// // 1.Memoization
// class Solution {
// private:
//     int solve(int m, int n, vector<vector<int>> &dp){

//         if(m==0 && n==0) return 1; // Since a path must have been taken to reach (0,0) from (m-1,n-1).
//         if(m<0 || n<0) return 0; // If any direction boundary is surpassed before reaching (0,0) then return 0.

//         if(dp[m][n]!=-1) return dp[m][n];
//         int up = solve(m-1,n,dp); // We are solving from (m-1,n-1) to (0,0).
//         int left = solve(m,n-1,dp);

//         return dp[m][n] = (up+left);
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,dp);
//     }
// };

// // 2.Tabulation
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int> (n,0));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0 && j==0) dp[i][j]=1;

//                 else
//                 {
//                     int up=0; int left=0;
//                     if(i>0) up = dp[i-1][j];
//                     if(j>0) left = dp[i][j-1];

//                     dp[i][j] = up + left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// 3. Space Optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) curr[j]=1;

                else
                {
                    int up=0; int left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};