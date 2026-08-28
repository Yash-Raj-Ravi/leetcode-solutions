// // 1.Recursion
// class Solution {
// private:
//     bool solve(int i,int j,string &s, string &t)
//     {
//         if(i<0) return true;
//         if(j<0) return false;

//         if(s[i]==t[j]) return solve(i-1,j-1,s,t);
//         return solve(i,j-1,s,t);
//     }
// public:
//     bool isSubsequence(string s, string t) {
//         int m = s.size();
//         int n = t.size();
//         return solve(m-1,n-1,s,t);
//     }
// };

// // 2.Memoization
class Solution {
private:
    bool solve(int i,int j,string &s, string &t,vector<vector<int>> &dp)
    {
        if(i<0) return true;
        if(j<0) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = solve(i-1,j-1,s,t,dp);
        return dp[i][j] = solve(i,j-1,s,t,dp);
    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};