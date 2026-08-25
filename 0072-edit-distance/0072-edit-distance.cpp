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

// 2.Memoization
class Solution {
private:
    int count(int i,int j,string &word1, string &word2,vector<vector<int>> &dp)
    {
        // Base cases:
        // If word1 is traversed fully, Then it needs operations = word2's remaining size to make them both equal
        if(i<0) return j+1;
        // If word2 is traversed fully, Then it needs operations = word1's remaining size to make them both equal
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]) return dp[i][j] = count(i-1,j-1,word1,word2,dp); // No operations required

        //else

        // Take the minimum of insert,delete and replace operations
        int r = 1 + count(i-1,j-1,word1,word2,dp); // Replace
        int in = 1 + count(i,j-1,word1,word2,dp); // Insert
        int d = 1 + count(i-1,j,word1,word2,dp); // Delete

        return dp[i][j] = min({r,in,d});
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return count(m-1,n-1,word1,word2,dp);
    }
};


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//     }
// };