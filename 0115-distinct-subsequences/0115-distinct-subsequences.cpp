// // 1.Recursion
// class Solution {
// private:
//     int count(int idx1,int idx2,string &s, string &t)
//     {
//         // Base cases must be in the following order:
//         if(idx2<0) return 1;
//         if(idx1<0) return 0;

//         if(s[idx1]==t[idx2]){
//             // If the chracter matches , Take it and continue as well as also consider the case of continuing without taking it to look for another occurrence of it.
//             return count(idx1-1,idx2-1,s,t) + count(idx1-1,idx2,s,t);
//         }
//         else
//         {
//             return count(idx1-1,idx2,s,t);
//         }
//     }
// public:
//     int numDistinct(string s, string t) {
//         if(t.size()>s.size()) return 0;
//         return count(s.size()-1,t.size()-1,s,t);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int count(int idx1,int idx2,string &s, string &t,vector<vector<int>> &dp)
//     {
//         // Base cases must be in the following order:
//         if(idx2<0) return 1;
//         if(idx1<0) return 0;

//         if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

//         if(s[idx1]==t[idx2]){
//             // If the chracter matches , Take it and continue as well as also consider the case of continuing without taking it to look for another occurrence of it.
//             return dp[idx1][idx2] = count(idx1-1,idx2-1,s,t,dp) + count(idx1-1,idx2,s,t,dp);
//         }
//         else
//         {
//           return dp[idx1][idx2] =  count(idx1-1,idx2,s,t,dp);
//         }
//     }
// public:
//     int numDistinct(string s, string t) {
//         int m = s.size();
//         int n = t.size();

//         if(t.size()>s.size()) return 0;

//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return count(s.size()-1,t.size()-1,s,t,dp);
//     }
// };

// 3.Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(t.size()>s.size()) return 0;

        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));

        for(int idx1=0;idx1<=m;idx1++) dp[idx1][0] = 1;

        for(int idx1=1;idx1<=m;idx1++)
        {
            for(int idx2=1;idx2<=n;idx2++)
            {
                if(s[idx1-1]==t[idx2-1]){
            // If the chracter matches , Take it and continue as well as also consider the case of continuing without taking it to look for another occurrence of it.
                long long ways = (long long) dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
                dp[idx1][idx2] = min(ways,(long long)INT_MAX);
            }
            else
            {
              dp[idx1][idx2] =  dp[idx1-1][idx2];
            }
        }
        }
    return dp[m][n];
    }
};