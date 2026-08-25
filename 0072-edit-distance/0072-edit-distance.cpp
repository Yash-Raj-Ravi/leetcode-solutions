// // 1.Recursion
// // The recursion count(i,j) represents the minimum number of operations required to convert word1(0,1,2,...i) to word2(0,1,2,...j)
// class Solution {
// private:
//     int count(int i,int j,string &word1, string &word2)
//     {
//         // Base cases:
//         // If word1 is traversed fully, Then it needs operations = word2's remaining size to make them both equal
//         if(i<0) return j+1;
//         // If word2 is traversed fully, Then it needs operations = word1's remaining size to make them both equal
//         if(j<0) return i+1;

//         if(word1[i]==word2[j]) return count(i-1,j-1,word1,word2); // No operations required

//         //else

//         // Take the minimum of insert,delete and replace operations
//         int r = 1 + count(i-1,j-1,word1,word2); // Replace
//         int in = 1 + count(i,j-1,word1,word2); // Insert
//         int d = 1 + count(i-1,j,word1,word2); // Delete

//         return min({r,in,d});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         return count(m-1,n-1,word1,word2);
//     }
// };

// // 2.Memoization
// class Solution {
// private:
//     int count(int i,int j,string &word1, string &word2,vector<vector<int>> &dp)
//     {
//         // Base cases:
//         // If word1 is traversed fully, Then it needs operations = word2's remaining size to make them both equal
//         if(i<0) return j+1;
//         // If word2 is traversed fully, Then it needs operations = word1's remaining size to make them both equal
//         if(j<0) return i+1;
        
//         if(dp[i][j]!=-1) return dp[i][j];

//         if(word1[i]==word2[j]) return dp[i][j] = count(i-1,j-1,word1,word2,dp); // No operations required

//         //else

//         // Take the minimum of insert,delete and replace operations
//         int r = 1 + count(i-1,j-1,word1,word2,dp); // Replace
//         int in = 1 + count(i,j-1,word1,word2,dp); // Insert
//         int d = 1 + count(i-1,j,word1,word2,dp); // Delete

//         return dp[i][j] = min({r,in,d});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return count(m-1,n-1,word1,word2,dp);
//     }
// };

// // 3.Tabulation
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m+1,vector<int>(n+1,0));

//         for(int i=0;i<=n;i++) dp[0][i] = i;
//         for(int j=0;j<=m;j++) dp[j][0] = j;

//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1]; // No operations required

//                 //else
//                 else{

//                 // Take the minimum of insert,delete and replace operations
//                 int r = 1 + dp[i-1][j-1]; // Replace
//                 int in = 1 + dp[i][j-1]; // Insert
//                 int d = 1 + dp[i-1][j]; // Delete

//                 dp[i][j] = min({r,in,d});
//                 }
//             }
//         }
//     return dp[m][n];
//     }
// };

// 4.Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=0;i<=n;i++) prev[i] = i;
        

        for(int i=1;i<=m;i++)
        {
            curr[0] = i;
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1]) curr[j] = prev[j-1]; // No operations required

                //else
                else{

                // Take the minimum of insert,delete and replace operations
                int r = 1 + prev[j-1]; // Replace
                int in = 1 + curr[j-1]; // Insert
                int d = 1 + prev[j]; // Delete

                curr[j] = min({r,in,d});
                }
            }
            prev = curr;
        }
    return prev[n];
    }
};