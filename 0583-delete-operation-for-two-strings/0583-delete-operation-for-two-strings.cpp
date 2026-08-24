class Solution {
private:
    int lcs(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int idx1=1;idx1<=m;idx1++)
        {
            for(int idx2=1;idx2<=n;idx2++)
            {
            // Characters match
            if(str1[idx1-1]==str2[idx2-1]) dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];

            // Characters do not match
            else dp[idx1][idx2] =  max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[m][n];
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==n) return 2*(m-lcs(word1,word2));
        return m>n ? m-lcs(word1,word2) + n - lcs(word1,word2)  :  n-lcs(word1,word2) + m-lcs(word1,word2);
    }
};