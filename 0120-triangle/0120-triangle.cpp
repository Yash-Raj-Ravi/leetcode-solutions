// // 1.Memoization-I
// class Solution {
// private:
//     int solve(int row,int i,vector<vector<int>>& triangle,vector<vector<int>>& dp){
//         if(row==0 && i==0) return triangle[row][i];
//         if(row<0 || i<0 || i>row) return INT_MAX;
//         if(dp[row][i]!=INT_MAX) return dp[row][i];

//         int up = solve(row-1,i,triangle,dp);
//         int up_left = solve(row-1,i-1,triangle,dp);

//         return dp[row][i] = triangle[row][i] + min(up,up_left);
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
//         int ans = INT_MAX;
//     // The ending row index is not fixed in terms where our search will end so we have to try out all the endings and take and minimum one.
//         for(int i = 0; i < m; i++) {
//             ans = min(ans, solve(m - 1, i, triangle, dp));
//         }

//         return ans;
//     }
// };

// It's better to start memoization from top in this case since top has only one element so we get to have a fixed beginning unlike above:

// 2.Memoization-II
class Solution {
private:
    int solve(int m,int row,int i,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row==m-1) return triangle[row][i];
    
        if(dp[row][i]!=INT_MAX) return dp[row][i];

        int down = solve(m,row+1,i,triangle,dp);
        int down_right = solve(m,row+1,i+1,triangle,dp);

        return dp[row][i] = triangle[row][i] + min(down,down_right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));

        return solve(m,0, 0, triangle, dp);
    
    }
};


// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//     }
// };


// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//     }
// };