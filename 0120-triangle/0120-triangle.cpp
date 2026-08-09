// 1.Memoization
class Solution {
private:
    int solve(int row,int i,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row==0 && i==0) return triangle[row][i];
        if(row<0 || i<0 || i>row) return INT_MAX;
        if(dp[row][i]!=INT_MAX) return dp[row][i];

        int up = solve(row-1,i,triangle,dp);
        int up_left = solve(row-1,i-1,triangle,dp);

        return dp[row][i] = triangle[row][i] + min(up,up_left);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        int ans = INT_MAX;

        for(int i = 0; i < m; i++) {
            ans = min(ans, solve(m - 1, i, triangle, dp));
        }

        return ans;
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