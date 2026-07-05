// // 1.Brute
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n = s.size();
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         vector<bool> available(n,true);
//         vector<bool> satisfied(g.size(),false);
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<g.size();j++)
//             {
//                 if(g[j]<=s[i] && available[i] && !satisfied[j])
//                 {
//                     ans++;
//                     available[i]=false;
//                     satisfied[j]=true;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// // 2.Memoization (Memory limit will exceed due to the constraints)
// class Solution {

// private:
// int helper(int studentIndex,int cookieIndex,vector<int>& g, vector<int>& s, vector<vector<int>> &dpmemo)
// {
//     if(studentIndex>=g.size() || cookieIndex>=s.size()) return 0;

//     if(dpmemo[studentIndex][cookieIndex]!=-1) return dpmemo[studentIndex][cookieIndex];

//     int result=0;
//     if(s[cookieIndex] >= g[studentIndex]){
//     // 1. Assign the Cookie and move to next student and next cookie
//     result = max(result, 1 + helper(studentIndex+1, cookieIndex+1,g,s,dpmemo));
//     }

//     // 2. Skip the Cookie and move to the next cookie for same student
//     result = max(result, helper(studentIndex, cookieIndex+1,g,s,dpmemo));
// // Store the result in Memoization table alongside returning it.
//  return dpmemo[studentIndex][cookieIndex]=result;
// }
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {

//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         vector<vector<int>> dpmemo(g.size(),vector<int> (s.size(),-1));
//         return helper(0,0,g,s,dpmemo);

//     }
// };

// // 3.Tabulation
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n = s.size();
//         int m = g.size();
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
//         for(int i=m-1;i>=0;i--)
//         {
//             for(int j=n-1;j>=0;j--)
//             {
//                 int skip = dp[i][j+1];
//                 int take=0;

//                 if(s[j]>=g[i])
//                 {
//                     take = 1 + dp[i+1][j+1];
//                 }
//                 dp[i][j] = max(skip,take);
//             }
//         }
//         return dp[0][0];
//     }
// };

// 4.Greedy (Optimal)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int studentIndex=0;
        int cookieIndex=0;
       
       while(studentIndex<m && cookieIndex<n)
       {
        if(s[cookieIndex]>=g[studentIndex])
        {
            studentIndex++;
        }
        cookieIndex++;
                
       }
        return studentIndex;
    }
};