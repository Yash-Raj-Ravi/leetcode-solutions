// // 1.Recursion
// class Solution {
// private:
//     bool solve(int i,int j,string &s, string &p)
//     {
//         // Base cases:
//         // If both strings get exhausted then its a match
//         if(i<0 && j<0) return true;

//         // If 1st string gets exhausted but 2nd string remains Then its like s="" and p="ab*?*" or p="***", If it is only *** then only p can match with empty s.
//         if(i<0 && j>=0) {
//             for(int idx=0;idx<=j;idx++) {
//                 if(p[idx]!='*') return false;
//             }
//             return true;
//         };

//         // If 2nd string gets exhausted and 1st one remains then its like s="abc" and p="", There is no way both can match in absence of * and ? in p.
//         if(i>=0 && j<0) return false;

//         if(s[i]==p[j] || p[j]=='?') return solve(i-1,j-1,s,p);

//         else if(p[j]=='*')
//          return solve(i-1,j,s,p) || solve(i,j-1,s,p); 
//         // solve(i-1,j,s,p) means we try to match one or more characters from s,  using * from p. 
//         // solve(i,j-1,s,p) means we decide to match no characters from s,  using * from p. 

//         // Else if characters do not match and no *
//         return false;

//     }
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         return solve(m-1,n-1,s,p);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     bool solve(int i,int j,string &s, string &p,vector<vector<int>> &dp)
//     {
//         // Base cases:
//         // If both strings get exhausted then its a match
//         if(i<0 && j<0) return true;

//         // If 1st string gets exhausted but 2nd string remains Then its like s="" and p="ab*?*" or p="***", If it is only *** then only p can match with empty s.
//         if(i<0 && j>=0) {
//             for(int idx=0;idx<=j;idx++) {
//                 if(p[idx]!='*') return false;
//             }
//             return true;
//         };

//         // If 2nd string gets exhausted and 1st one remains then its like s="abc" and p="", There is no way both can match in absence of * and ? in p.
//         if(i>=0 && j<0) return false;

//         if(dp[i][j]!=-1) return dp[i][j];

//         if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(i-1,j-1,s,p,dp);

//         else if(p[j]=='*')
//          return dp[i][j] = solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp); 
//         // solve(i-1,j,s,p) means we try to match one or more characters from s,  using * from p. 
//         // solve(i,j-1,s,p) means we decide to match no characters from s,  using * from p. 

//         // Else if characters do not match and no *
//         return false;

//     }
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         return solve(m-1,n-1,s,p,dp);
//     }
// };

// 3.Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));

        dp[0][0] = true;
        for(int i=1;i<=m;i++) dp[i][0] = false;

        for(int j=1;j<=n;j++) {
          if(p[j-1] == '*')
           dp[0][j] = dp[0][j-1];
          else
           dp[0][j] = false;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')  dp[i][j] = dp[i-1][j-1];

                else if(p[j-1]=='*')
                 dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
                // solve(i-1,j,s,p) means we try to match one or more characters from s,  using * from p. 
                // solve(i,j-1,s,p) means we decide to match no characters from s,  using * from p. 

                // Else if characters do not match and no *
                else
                dp[i][j] = false;
            }
        }
    return dp[m][n];
    }
};